// Minimum Path Sum
// leetcode - 64
class Solution {
public:
    int recursion(int row,int col,int n,int m,vector<vector<int>>& grid)
    {
        if(row==n-1 && col==m-1)
            return grid[row][col];
        int right = INT_MAX,down = INT_MAX;
        if(col+1<m)
            right = recursion(row,col+1,n,m,grid);
        if(row+1<n)
            down = recursion(row+1,col,n,m,grid);
        if(right == INT_MAX && down==INT_MAX)
            return grid[row][col];
        else if(right == INT_MAX)
            return down+grid[row][col];
        else if(down==INT_MAX)
            return right+grid[row][col];
        return min(right,down)+grid[row][col];
    }
    int memoization(int row,int col,int n,int m,vector<vector<int>>& grid,vector<vector<long long>> &dp)
    {
        if(row==n-1 && col==m-1)
            return grid[row][col];
        if(dp[row][col]!=-1)
            return dp[row][col];
        int right = INT_MAX,down = INT_MAX;
        if(col+1<m)
            right = memoization(row,col+1,n,m,grid,dp);
        if(row+1<n)
            down = memoization(row+1,col,n,m,grid,dp);
        if(right == INT_MAX && down==INT_MAX)
            return dp[row][col] = grid[row][col];
        else if(right == INT_MAX)
            return dp[row][col] = down+grid[row][col];
        else if(down==INT_MAX)
            return dp[row][col] = right+grid[row][col];
        return dp[row][col] = min(right,down)+grid[row][col];
    }
    int minPathSum(vector<vector<int>>& grid) {
        // recursion tc-o(2^(n*m)) sc-o(n+m+nm)
        /*int n = grid.size(),m = grid[0].size();
        return recursion(0,0,n,m,grid);*/

        // memoization tc-o(m*n) sc-o(m+n+m*n)
        /*int n = grid.size(),m = grid[0].size();
        vector<vector<long long>> dp(n,vector<long long>(m,-1));
        return memoization(0,0,n,m,grid,dp);*/

        // tabulation tc-o(n*m) sc-o(n*m)
        /*int n = grid.size(),m = grid[0].size();
        vector<vector<long long>> dp(n,vector<long long>(m,-1));
        for(int row = n-1;row>=0;row--)
        {
            for(int col=m-1;col>=0;col--)
            {
                if(row==n-1 && col==m-1)
                    dp[row][col] = grid[row][col];
                int right = INT_MAX,down = INT_MAX;
                if(col+1<m)
                    right = dp[row][col+1];
                if(row+1<n)
                    down = dp[row+1][col];
                if(right == INT_MAX && down==INT_MAX)
                    dp[row][col] = grid[row][col];
                else if(right == INT_MAX)
                    dp[row][col] = down+grid[row][col];
                else if(down==INT_MAX)
                    dp[row][col] = right+grid[row][col];
                else dp[row][col] = min(right,down)+grid[row][col];
            }
        }
        return dp[0][0];*/

        //space optimization tc-o(n*m) sc-o(2m)
        int n = grid.size(),m = grid[0].size();
        vector<long long> dp(m,0);
        for(int row = n-1;row>=0;row--)
        {
            vector<long long> temp(m,0);
            for(int col=m-1;col>=0;col--)
            {
                if(row==n-1 && col==m-1)
                    temp[col] = grid[row][col];
                int right = INT_MAX,down = INT_MAX;
                if(col+1<m)
                    right = temp[col+1];
                if(row+1<n)
                    down = dp[col];
                if(right == INT_MAX && down==INT_MAX)
                    temp[col] = grid[row][col];
                else if(right == INT_MAX)
                    temp[col] = down+grid[row][col];
                else if(down==INT_MAX)
                    temp[col] = right+grid[row][col];
                else temp[col] = min(right,down)+grid[row][col];
            }
            dp = temp;
        }
        return dp[0];
    }
};