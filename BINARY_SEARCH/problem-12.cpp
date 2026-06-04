// find how many times array is rotated
class Solution {
public:
    int findKRotation(vector<int> &nums)  {
        // brute -> linear iteration
        /*int n = nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i]<nums[i-1])
                return i;
        }
        return 0;*/
        // optimal-1 (binary search by keeping track of largest element)
        /*int n=nums.size(),maxi = INT_MIN,low = 0,high = n-1,ans=0;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(nums[low]<=nums[mid])
            {
                if(maxi<=nums[mid])
                {
                    maxi = nums[mid];
                    ans = ans + mid-low+1;
                    low = mid+1;
                }
                else break;
            }
            else high = mid-1;
        }
        return ans;*/
        // optimal-2 (binary search by keeping track of minimum elemet);
        int n = nums.size(),ans=-1,low = 0,high = n-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(nums[low]<=nums[mid])
            {
                if(ans ==-1 || nums[ans]>nums[low])
                    ans = low;
                low = mid+1;
            }
            else{
                if(ans == -1 || nums[ans]>nums[mid])
                    ans = mid;
                high = mid-1;
            }
        }
        return ans;
    }
};