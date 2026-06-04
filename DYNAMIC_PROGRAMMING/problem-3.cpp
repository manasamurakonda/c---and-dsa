// GFG - Frog Jump 
class Solution {
  public:
    int recursion(int ind,vector<int> &height,vector<int> &dp)
    {
        if(dp[ind]!=-1)
            return dp[ind];
        int left = INT_MAX,right = INT_MAX;
        left = recursion(ind-1,height,dp) + abs(height[ind-1]-height[ind]);
        if(ind-2>=0)
            right = recursion(ind-2,height,dp) + abs(height[ind-2]-height[ind]);
        return dp[ind] = min(left,right);
    }
    int minCost(vector<int>& height) {
        // memoization tc-o(n) sc-o(2n)
        /*int n = height.size();
        vector<int> dp(n,-1);
        dp[0] = 0;
        return recursion(n-1,height,dp);*/
        
        // tabulation tc-o(n) sc-o(n)
        /*int n = height.size();
        vector<int> dp(n,-1);
        dp[0] = 0;
        for(int i=1;i<n;i++)
        {
            int left,right = INT_MAX;
            left = dp[i-1] + abs(height[i-1]-height[i]);
            if(i-2 >= 0)
                right = dp[i-2] + abs(height[i-2]-height[i]);
            dp[i] = min(left,right);
        }
        return dp[n-1];*/
        
        // space optimization tc-o(n) sc-o(1)
        int n = height.size();
        int prev1 = 0,prev2 = 0;
        for(int i=1;i<n;i++)
        {
            int left,right = INT_MAX;
            left = prev1 + abs(height[i-1]-height[i]);
            if(i-2>=0)
                right = prev2 + abs(height[i-2]-height[i]);
            prev2 = prev1;
            prev1 = min(left,right);
        }
        return prev1;
    }
};