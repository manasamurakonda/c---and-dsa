// find the smallest divisor given a threshold
// leetcode - 1283
class Solution {
public:
    int check(vector<int>& nums, int threshold,int x)
    {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            ans = ans + ceil(nums[i]/(double)x);
        }
        if(ans<=threshold)
            return 1;
        return 0;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        // brute - > linear search
        /*int maxi = *max_element(nums.begin(),nums.end());
        for(int i=1;i<=maxi;i++)
        {
            if(check(nums,threshold,i)==1)
                return i;
        }
        return -1;*/

        // optimal -> binary search
        int low = 1 ,high = *max_element(nums.begin(),nums.end());
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(check(nums,threshold,mid)==1)
                high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};