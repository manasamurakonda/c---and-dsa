// GFG - 0 - 1 Knapsack Problem
class Solution {
  public:
    int recursion(int ind,int n,int W,vector<int> &val,vector<int> &wt,int value,int weight)
    {
        if(ind == n)
        {
            if(weight<=W)
                return value;
            return 0;
        }
        
        int x = recursion(ind+1,n,W,val,wt,value+val[ind],weight+wt[ind]);
        int y = recursion(ind+1,n,W,val,wt,value,weight);
        return max(x,y);
    }
    int memoization(int ind,int n,int W,vector<int> &val,vector<int> &wt,vector<vector<int>> &dp)
    {
        if(ind==n)
        {
            return 0;
        }
        if(dp[ind][W]!=-1)
            return dp[ind][W];
        int x=0,y=0;
        if(W>=wt[ind])
            x = val[ind]+memoization(ind+1,n,W-wt[ind],val,wt,dp);
        y = memoization(ind+1,n,W,val,wt,dp);
        return dp[ind][W] = max(x,y);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // recursion
        /*int n = val.size();
        return recursion(0,n,W,val,wt,0,0);*/
        
        // memoization
        /*int n = val.size();
        vector<vector<int>> dp(n+1,vector<int> (W+1,-1));
        return memoization(0,n,W,val,wt,dp);*/
        
        //tabulation
        /*int n = val.size();
        vector<vector<int>> dp(n+1,vector<int> (W+1,-1));
        for(int i=0;i<W+1;i++)
        {
            dp[n][i] = 0;
        }
        for(int ind = n-1;ind>=0;ind--)
        {
            for(int weight = 0;weight<=W;weight++){
                int x=0,y=0;
                if(weight>=wt[ind]){
                    x = val[ind]+dp[ind+1][weight-wt[ind]];
                }
                y = dp[ind+1][weight];
                dp[ind][weight] = max(x,y);
            }
        }
        return dp[0][W];*/
        
        // space optimization using two arrays
        /*int n = val.size();
        vector<int> dp(W+1,0);
        for(int ind = n-1;ind>=0;ind--)
        {
            vector<int> temp(W+1,0);
            for(int weight = 0;weight<=W;weight++){
                int x=0,y=0;
                if(weight>=wt[ind]){
                    x = val[ind]+dp[weight-wt[ind]];
                }
                y = dp[weight];
                temp[weight] = max(x,y);
            }
            dp = temp;
        }
        return dp[W];*/
        
        // space optimization usong only one array optimization
        /*int n = val.size();
        vector<int> dp(W+1,0);
        for(int ind = n-1;ind>=0;ind--)
        {
            for(int weight = W;weight>=0;weight--){
                int x=0,y=0;
                if(weight>=wt[ind]){
                    x = val[ind]+dp[weight-wt[ind]];
                }
                y = dp[weight];
                dp[weight] = max(x,y);
            }
        }
        return dp[W];*/
    }
};