// GfG - Longest Increasing Subsequence
class Solution {
  public:
    int recursion(int ind,int prev,vector<int> &arr)
    {
        if(ind==arr.size())
            return 0;
        int pick = 0,not_pick = 0;
        if(prev==-1 || arr[prev]<arr[ind])
            pick = 1 + recursion(ind+1,ind,arr);
        not_pick = recursion(ind+1,prev,arr);
        return max(pick,not_pick);
    }
    int memoization(int ind,int prev,vector<int> &arr,vector<vector<int>> &dp)
    {
        if(ind==arr.size())
            return 0;
        if(dp[ind][prev]!=-1)
            return dp[ind][prev];
        int pick = 0,not_pick = 0;
        if(prev==0 || arr[prev-1]<arr[ind])
            pick = 1 + memoization(ind+1,ind+1,arr,dp);
        not_pick = memoization(ind+1,prev,arr,dp);
        return dp[ind][prev] = max(pick,not_pick);
    }
    int lis(vector<int>& arr) {
        // recursion
        /*int n = arr.size();
        return recursion(0,-1,arr);*/
        
        // memoization
        /*int n = arr.size();
        vector<vector<int>> dp(n,vector<int> (n+1,-1));
        return memoization(0,0,arr,dp);*/
        
        // tabulation
        /*int n = arr.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        for(int ind=0;ind<=n;ind++)
            dp[n][ind] = 0;
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int prev=0;prev<=n;prev++)
            {
                int pick = 0,not_pick = 0;
                if(prev==0 || arr[prev-1]<arr[ind])
                    pick = 1 + dp[ind+1][ind+1];
                not_pick = dp[ind+1][prev];
                dp[ind][prev] = max(pick,not_pick);
            }
        }
        return dp[0][0];*/
        
        // space optimization
        int n = arr.size();
        vector<int> cur(n+1,0),dp(n+1,0);
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int prev=0;prev<=n;prev++)
            {
                int pick = 0,not_pick = 0;
                if(prev==0 || arr[prev-1]<arr[ind])
                    pick = 1 + dp[ind+1];
                not_pick = dp[prev];
                cur[prev] = max(pick,not_pick);
            }
            dp = cur;
        }
        return dp[0];
    }
};