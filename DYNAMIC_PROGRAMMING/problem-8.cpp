// Unique Paths
// leetcode - 62
class Solution {
public:
    int recursion(int row,int col,int m,int n)
    {
        if(row==m-1 && col==n-1)
            return 1;
        int right = 0,down = 0;
        if(col+1<n)
            right = recursion(row,col+1,m,n);
        if(row+1<m)
            down = recursion(row+1,col,m,n);
        return right+down;
    }
    int memoization(int row,int col,int m,int n,vector<vector<int>> &dp)
    {
        if(row == m-1 && col==n-1)
            return 1;
        if(dp[row][col]!=-1)
            return dp[row][col];
        int right = 0,down = 0;
        if(col+1<n)
            right = memoization(row,col+1,m,n,dp);
        if(row+1<m)
            down = memoization(row+1,col,m,n,dp);
        return dp[row][col] = right+down;
    }
    int uniquePaths(int m, int n) {
        // recursion tc-o(2^(m*n)) sc-o(m+n+m*n)
        /*return recursion(0,0,m,n);*/

        // memoization tc-o(m*n) sc-o(m+n + m*n)
        /*vector<vector<int>> dp(m,vector<int>(n,-1));
        return memoization(0,0,m,n,dp);*/
        
        // tabulation tc-o(m*n) sc-o(m*n)
        /*vector<vector<int>> dp(m,vector<int>(n,-1));
        dp[m-1][n-1] = 1;
        for(int row=m-1;row>=0;row--)
        {
            for(int col=n-1;col>=0;col--)
            {
                if(row == m-1 && col==n-1)
                    dp[row][col] = 1;
                else{
                    int right = 0,down = 0;
                    if(col+1<n)
                        right = dp[row][col+1];
                    if(row+1<m)
                        down = dp[row+1][col];
                    dp[row][col] = right+down;
                }
            }
        }
        return dp[0][0];*/

        // space optimization tc-o(m*n) sc-o(2n)
        vector<int> dp(n,0);
        dp[n-1]=1;
        for(int row=m-1;row>=0;row--)
        {
            vector<int> temp(n,0);
            for(int col=n-1;col>=0;col--)
            {
                if(row == m-1 && col==n-1)
                    temp[col] = 1;
                else{
                    if(col+1<n)
                        temp[col] = dp[col] + temp[col+1];
                    else temp[col] = dp[col];
                }
            }
            dp = temp;
        }
        return dp[0];
    }
};