// house robber - 2
// leetcode - 213
class Solution {
public:
    int recursion(int ind,int first,vector<int> &nums)
    {
        if(ind<first)
            return 0;
        int left,right;

        left = recursion(ind-2,first,nums)+nums[ind];
        right = recursion(ind-1,first,nums);
        return max(right,left);
    }
    int memoization(int ind,int first,vector<int> &nums,vector<int> &dp)
    {
        if(ind<first)
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        int left,right;
        left = memoization(ind-2,first,nums,dp)+nums[ind];
        right = memoization(ind-1,first,nums,dp);
        return dp[ind] = max(right,left);
    }
    int tabulation(int first,int last,vector<int> &nums,vector<int> &dp)
    {
        int cost = 0;
        for(int i=first;i<=last;i++)
        {
            int left,right;
            if(i-2<0)
                left = 0;
            else
                left = dp[i-2] + nums[i];
            right = dp[i-1];
            dp[i] = max(left,right);
        }
        return dp[last];
    }
    int space_optimization(int first,int last,vector<int> &nums)
    {
        int cost = 0,prev1 = nums[first-1],prev2 = 0;
        for(int i=first;i<=last;i++)
        {
            int left,right;
            if(i-2<0)
                left = 0;
            else
                left = prev2 + nums[i];
            right = prev1;
            prev2 = prev1;
            prev1 = max(left,right);
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        // recursion
        /*int n = nums.size();
        if(n==1)
            return nums[0];
        return max(recursion(n-2,0,nums),recursion(n-1,1,nums));*/

        // memoization tc-o(n) sc-o(2n)
        /*int n = nums.size();
        if(n==1)
            return nums[0];
        vector<int> dp(n,-1);
        int first = memoization(n-2,0,nums,dp);
        fill(dp.begin(), dp.end(), -1);
        int second = memoization(n-1,1,nums,dp);
        return max(first,second);*/

        // tabulation tc-o(n) sc-o(n)
        /*int n = nums.size();
        if(n==1)
            return nums[0];
        vector<int> dp(n);
        dp[0] = 0;
        dp[1] = nums[1];
        int first = tabulation(2,n-1,nums,dp);
        dp[0] = nums[0];
        int second = tabulation(1,n-2,nums,dp);
        return max(first,second);*/

        // space optimization tc-o(n) sc-o(1)
        int n = nums.size();
        if(n==1)
            return nums[0];
        int first = space_optimization(2,n-1,nums);
        int second = space_optimization(1,n-2,nums);
        return max(first,second);
    }
};