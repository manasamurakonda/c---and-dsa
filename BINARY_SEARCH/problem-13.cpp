// single element in a sorted array
// leetcode - 540
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // brute -> hashing
        /*int n=nums.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
        }
        for(auto it : m)
        {
            if(it.second==1)
                return it.first;
        }
        return -1;*/

        // better1 -> xor
        /*int ans = 0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            ans = ans ^ nums[i];
        }
        return ans;*/

        // better2 -> linear search

        // optimal1 -> take advantage of sorted and use binary search(based on length of right half)
        /*int n = nums.size(),low = 0,high = n-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(mid-1>=0 && nums[mid]==nums[mid-1] )
            {
                if((high-mid)%2==0)
                    high = mid-2;
                else
                    low = mid+1;
            }
            else if(mid+1<n && nums[mid]==nums[mid+1])
            {
                if((high-(mid+1))%2==0)
                    high = mid-1;
                else low = mid+2;
            }
            else return nums[mid];
        }
        return -1;*/

        // optimal2 -> binary search based on odd,even or even , odd
        int n = nums.size(),low = 1,high = n-2;
        if(n==1)
            return nums[0];
        if(nums[0]!=nums[1])
            return nums[0];
        if(nums[n-1]!=nums[n-2])
            return nums[n-1];
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])
                return nums[mid];
            else if(nums[mid]==nums[mid+1])
            {
                if(mid%2==0)
                    low = mid+1;
                else high = mid-1;
            }
            else{
                if(mid%2==0)
                    high = mid-1;
                else low = mid+1;
            }
        }
        return -1;
    }
};