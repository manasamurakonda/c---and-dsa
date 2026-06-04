// maximum subarray sum leetcode - 53

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // brute -> nested loops
        /*int n = nums.size();
        int ans = INT_MIN,count = 0;
        for(int i=0;i<n;i++)
        {
            count = 0;
            for(int j = i;j<n;j++)
            {
                count = count+ nums[j];
                ans = max(ans,count);
            }
            ans = max(ans,count);
        }
        return ans;*/


        // optimal - > kadanes algorithm
        int n = nums.size();
        int ans = INT_MIN, sum = 0;
        for(int i=0;i<n;i++)
        {
            sum = sum + nums[i];
            ans = max(ans, sum);
            if(sum<0)
            {
                sum = 0;
            }
        }
        return ans;
    }
};