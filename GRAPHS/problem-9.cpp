// number of enclaves
// leetcode - 1020
class Solution {
public:
    void dfs(int row,int col,int n,int m,vector<vector<int>>& grid,vector<vector<bool>> &visited,vector<int> &delrow,vector<int> &delcol)
    {
        visited[row][col] = true;
        for(int i=0;i<4;i++)
        {
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]==1)
            dfs(nrow,ncol,n,m,grid,visited,delrow,delcol);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        // optimal -> traverse edges of the grid tc-o(n+m+5nm) sc-o(2nm)
        int ans = 0,n = grid.size(),m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool> (m,false));
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,1,0,-1};
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==1 && !visited[i][0])
                dfs(i,0,n,m,grid,visited,delrow,delcol);

            if(grid[i][m-1]==1 && !visited[i][m-1])
                dfs(i,m-1,n,m,grid,visited,delrow,delcol);
        }

        for(int i=0;i<m;i++)
        {
            if(grid[0][i]==1 && !visited[0][i])
                dfs(0,i,n,m,grid,visited,delrow,delcol);
            
            if(grid[n-1][i]==1 && !visited[n-1][i])
                dfs(n-1,i,n,m,grid,visited,delrow,delcol);
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] && grid[i][j]==1)
                    ans++;
            }
        }
        return ans;
    }
};