// split array largest sum
// leetcode - 410
class Solution {
public:
    int check(vector<int>& nums, int k,int x)
    {
        int n = nums.size(),ans = 0,sum=0;
        for(int i=0;i<n;i++)
        {
            sum = sum + nums[i];
            if(sum>x)
            {
                ans++;
                sum = nums[i];
            }
        }
        ans++;
        if(ans<=k)
            return 1;
        return 0;
    }
    int splitArray(vector<int>& nums, int k) {
        // brute -> linear iteration
        /*int n= nums.size();
        int mini = *max_element(nums.begin(),nums.end());
        int maxi = accumulate(nums.begin(),nums.end(),0);
        for(int i=mini;i<=maxi;i++)
        {
            if(check(nums,k,i)==1)
                return i;
        }
        return -1;*/

        // optimal -> binary search on answers2 max(min);
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(check(nums,k,mid)==1)
                high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};