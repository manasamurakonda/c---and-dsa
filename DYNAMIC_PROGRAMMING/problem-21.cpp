// target sum
// leetcode - 494
// same as program - 18
class Solution {
public:
    int recursion(int ind,int n,vector<int> &nums,int target,int sum1,int sum2)
    {
        if(ind == n)
        {
            if(sum1-sum2==target)
                return 1;
            return 0;
        }

        int x = recursion(ind+1,n,nums,target,sum1+nums[ind],sum2);
        int y = recursion(ind+1,n,nums,target,sum1,sum2+nums[ind]);
        return x+y;
    }
    int memoization(int ind,int n,vector<int> &nums,int target,int sum1,int sum2,vector<vector<int>> &dp)
    {
        if(ind == n)
        {
            if(sum1-sum2==target)
                return 1;
            return 0;
        }
        if(dp[sum1][sum2]!=-1)
            return dp[sum1][sum2];
        int x = 0,y=0;
        x = memoization(ind+1,n,nums,target,sum1+nums[ind],sum2,dp);
        y = memoization(ind+1,n,nums,target,sum1,sum2+nums[ind],dp);
        return dp[sum1][sum2] = x+y;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return recursion(0,n,nums,target,0,0);
        // memoization
        /*int sum = accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> dp(sum+1,vector<int> (sum+1,-1));
        return memoization(0,n,nums,target,0,0,dp);*/
    }
};