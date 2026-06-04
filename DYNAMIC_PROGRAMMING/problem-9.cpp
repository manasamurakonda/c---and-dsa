// Unique Paths II
// leetcode - 63
class Solution {
public:
    int recursion(int row,int col,int n,int m,vector<vector<int>>& obstacleGrid)
    {
        if(row == n-1 && col==m-1)
            return 1;
        int right = 0,down = 0;
        if(col+1<m && obstacleGrid[row][col+1]==0)
            right = recursion(row,col+1,n,m,obstacleGrid);
        if(row+1<n && obstacleGrid[row+1][col]==0)
            down = recursion(row+1,col,n,m,obstacleGrid);
        return right+down;
    }
    int memoization(int row,int col,int n,int m,vector<vector<int>>& obstacleGrid,vector<vector<int>> &dp)
    {
        if(row == n-1 && col==m-1)
            return 1;
        if(dp[row][col]!=-1)
            return dp[row][col];
        int right = 0,down = 0;
        if(col+1<m && obstacleGrid[row][col+1]==0)
            right = memoization(row,col+1,n,m,obstacleGrid,dp);
        if(row+1<n && obstacleGrid[row+1][col]==0)
            down = memoization(row+1,col,n,m,obstacleGrid,dp);
        return dp[row][col] =  right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // recursion tc-o(2^(m*n)) sc-o(m+n+m*n)
        /*int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1)
            return 0;
        return recursion(0,0,n,m,obstacleGrid);*/

        // memoization tc-o(n*m) sc-o(m+n+m*n)
        /*int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1)
            return 0;
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return memoization(0,0,n,m,obstacleGrid,dp);*/

        // tabulation tc-o(n*m) sc-o(n*m)
        /*int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1)
            return 0;
        vector<vector<long long>> dp(n,vector<long long> (m,-1));
        for(int row=n-1;row>=0;row--)
        {
            for(int col=m-1;col>=0;col--)
            {
                if(row==n-1 && col==m-1)
                    dp[row][col] = 1;
                else{
                    long long right = 0,down = 0;
                    if(col+1<m && obstacleGrid[row][col+1]==0)
                        right = dp[row][col+1];
                    if(row+1<n && obstacleGrid[row+1][col]==0)
                        down = dp[row+1][col];
                    dp[row][col] =  right+down;
                }
            }
        }
        return dp[0][0];*/

        // space optimization tc-o(n*m) sc-o(m)
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1)
            return 0;
        vector<long long> dp(m,0);
        for(int row = n-1;row>=0;row--)
        {
            vector<long long> temp(m,0);
            for(int col=m-1;col>=0;col--)
            {
                if(obstacleGrid[row][col]==1)
                    temp[col] = 0;
                else if(row==n-1 && col==m-1)
                    temp[col] = 1;
                else{
                    if(col+1<m)
                        temp[col] = dp[col]+temp[col+1];
                    else temp[col] = dp[col];
                }
            }
            dp = temp;
        }
        return dp[0];
    }
};