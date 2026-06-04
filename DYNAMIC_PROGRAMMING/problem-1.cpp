// fibonacci number
// leetcode - 509
class Solution {
public:
    int fibonacci_memoization(int n,vector<int> &dp)
    {
        if(n<=1)
            return n;
        if(dp[n]!=-1)
            return dp[n];
        return dp[n] = fibonacci_memoization(n-1,dp)+fibonacci_memoization(n-2,dp);
    }
    int fib(int n) {
        // memoization -> tc-o(n) sc-o(2n)
        /*vector<int> dp(n+1,-1);
        return fibonacci_memoization(n,dp);*/

        // tabulation -> tc-o(n) sc-o(n)
        /*if(n<=1)
            return n;
        vector<int> dp(n+1,-1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2;i<=n;i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];*/

        // space optimization tc-o(n) sc-o(1)
        if(n<=1)
            return n;
        int prev1,prev2;
        prev1 = 1;
        prev2 = 0;
        int cur;
        for(int i=2;i<=n;i++)
        {
            cur = prev1+ prev2;
            prev2 = prev1;
            prev1 = cur; 
        }
        return cur;
    }
};