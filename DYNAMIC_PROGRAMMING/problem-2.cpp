// climbing stairs
// leetcode - 70
class Solution {
public:
    int memoization(int n,vector<int> &dp)
    {
        if(dp[n]==-1)
            return dp[n] = memoization(n-1,dp)+memoization(n-2,dp);  
        return dp[n];
    }
    int climbStairs(int n) {
        // memoization tc-o(n) sc-o(2n)
        /*vector<int> dp(n+1,-1);
        dp[0] = 1;
        dp[1] = 1;
        return memoization(n,dp);*/

        // tabulation tc-o(n) sc-o(n)
        /*vector<int> dp(n+1,-1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<=n;i++)
        {
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];*/

        // space optimization tc-o(n) sc-o(1)
        int prev1 = 1,prev2 = 1;
        for(int i=2;i<=n;i++)
        {
            int cur = prev1+prev2;
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};