// GFG - Geek's Training
class Solution {
  public:
    int recursion(int row,int n,int prev,vector<vector<int>>& mat,vector<vector<int>> &dp)
    {
        if(row == n)
            return 0;
        int maxi = 0;
        if(dp[row][prev]!=-1)
            return dp[row][prev];
        for(int i=0;i<3;i++)
        {
            if(i!=prev)
            {
                maxi = max(maxi,recursion(row+1,n,i,mat,dp)+mat[row][i]);
            }
        }
        return dp[row][prev] = maxi;
    }
    int maximumPoints(vector<vector<int>>& mat) {
        // memoization tc-o(n) sc-o(n+4*n);
        /*int n = mat.size();
        vector<vector<int>> dp(n+1,vector<int>(4,-1));
        return recursion(0,n,3,mat,dp);*/
        
        // tabulation tc-o(n) sc-o(4*n)
        /*int n = mat.size();
        vector<vector<int>> dp(n+1,vector<int>(4,-1));
        dp[n][0] = 0;
        dp[n][1] = 0;
        dp[n][2] = 0;
        for(int row = n-1;row>=0;row--)
        {
            for(int prev=0;prev<4;prev++){
                int maxi = 0;
                for(int i=0;i<3;i++)
                {
                    if(i!=prev)
                    {
                        maxi = max(maxi,dp[row+1][i]+mat[row][i]);
                    }
                }
                dp[row][prev] = maxi;
            }
        }
        return dp[0][3];*/
        
        // space optimization tc-o(n) sc-o(2*4)
        int n = mat.size();
        vector<int> dp(4,0);
        for(int row = n-1;row>=0;row--)
        {
            vector<int> temp(4,0);
            for(int prev=0;prev<4;prev++){
                int maxi = 0;
                for(int i=0;i<3;i++)
                {
                    if(i!=prev)
                    {
                        maxi = max(maxi,dp[i]+mat[row][i]);
                    }
                }
                temp[prev] = maxi;
            }
            dp = temp;
        }
        return dp[3];
    }
};