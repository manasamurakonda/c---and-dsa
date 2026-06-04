// cherry pickup - 2
// leetcode - 1463
class Solution {
public:
    int recursion(int row,int col1,int col2,int n,int m,vector<vector<int>>& grid)
    {
        if(row == n-1)
        {
            if(col1==col2)
                return grid[row][col1];
            return grid[row][col1]+grid[row][col2];
        }
        vector<int> pos = {-1,0,1};
        int ans = INT_MIN;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                int ncol1,ncol2;
                ncol1 = col1+pos[i];
                ncol2 = col2+pos[j];
                if(ncol1>=0 && ncol1<m && ncol2>=0 && ncol2<m)
                {
                    ans = max(ans,recursion(row+1,ncol1,ncol2,n,m,grid));
                }
            }
        }
        if(col1==col2)
            return ans + grid[row][col1];
        return ans+grid[row][col1]+grid[row][col2];
    }
    int memoization(int row,int col1,int col2,int n,int m,vector<vector<int>>& grid,vector<vector<vector<int>>> &dp)
    {
        if(row == n-1)
        {
            if(col1==col2)
                return grid[row][col1];
            return grid[row][col1]+grid[row][col2];
        }
        if(dp[row][col1][col2]!=-1)
            return dp[row][col1][col2];
        vector<int> pos = {-1,0,1};
        int ans = INT_MIN;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                int ncol1,ncol2;
                ncol1 = col1+pos[i];
                ncol2 = col2+pos[j];
                if(ncol1>=0 && ncol1<m && ncol2>=0 && ncol2<m)
                {
                    ans = max(ans,memoization(row+1,ncol1,ncol2,n,m,grid,dp));
                }
            }
        }
        if(col1==col2)
            return dp[row][col1][col2] = ans + grid[row][col1];
        return dp[row][col1][col2] = ans+grid[row][col1]+grid[row][col2];
    }
    int cherryPickup(vector<vector<int>>& grid) {
        //recursion tc-o(3^n * 3^n) sc-o(n)
        /*int n = grid.size(),m=grid[0].size();
        return recursion(0,0,m-1,n,m,grid);*/

        // memoization tc-o(n*m*m) sc-o(n*m*m)+o(n)
        /*int n = grid.size(),m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return memoization(0,0,m-1,n,m,grid,dp);*/

        // tabulation tc-o(n*m*m) sc-o(n*m*m)
        /*int n = grid.size(),m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==j)
                    dp[n-1][i][j] = grid[n-1][i];
                else
                    dp[n-1][i][j] = grid[n-1][i]+grid[n-1][j];
            }
        }
        int col1 = 0,col2 = m-1;
        for(int row = n-2;row>=0;row--)
        {
            for(int col1 = 0;col1<m;col1++)
            {
                for(int col2 = 0;col2<m;col2++)
                {
                    vector<int> pos = {-1,0,1};
                    int ans = INT_MIN;
                    for(int i=0;i<3;i++)
                    {
                        for(int j=0;j<3;j++)
                        {
                            int ncol1,ncol2;
                            ncol1 = col1+pos[i];
                            ncol2 = col2+pos[j];
                            if(ncol1>=0 && ncol1<m && ncol2>=0 && ncol2<m)
                            {
                                if(ans<dp[row+1][ncol1][ncol2]){
                                    ans = dp[row+1][ncol1][ncol2];
                                }
                            }
                        }
                    }
                    if(col1==col2)
                        dp[row][col1][col2] = ans + grid[row][col1];
                    else
                        dp[row][col1][col2] = ans+grid[row][col1]+grid[row][col2];
                }
            }
        }
        return dp[0][0][m-1];*/

        // space optimization tc-o(n*m*m) sc-o(m*m)
        int n = grid.size(),m=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(m,-1));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==j)
                    dp[i][j] = grid[n-1][i];
                else
                    dp[i][j] = grid[n-1][i]+grid[n-1][j];
            }
        }
        int col1 = 0,col2 = m-1;
        for(int row = n-2;row>=0;row--)
        {
            vector<vector<int>> temp(m,vector<int>(m,-1));
            for(int col1 = 0;col1<m;col1++)
            {
                for(int col2 = 0;col2<m;col2++)
                {
                    vector<int> pos = {-1,0,1};
                    int ans = INT_MIN;
                    for(int i=0;i<3;i++)
                    {
                        for(int j=0;j<3;j++)
                        {
                            int ncol1,ncol2;
                            ncol1 = col1+pos[i];
                            ncol2 = col2+pos[j];
                            if(ncol1>=0 && ncol1<m && ncol2>=0 && ncol2<m)
                            {
                                if(ans<dp[ncol1][ncol2]){
                                    ans = dp[ncol1][ncol2];
                                }
                            }
                        }
                    }
                    if(col1==col2)
                        temp[col1][col2] = ans + grid[row][col1];
                    else
                        temp[col1][col2] = ans+grid[row][col1]+grid[row][col2];
                }
            }
            dp = temp;
        }
        return dp[0][m-1];
    }
};