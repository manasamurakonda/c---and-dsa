// number of islands
// leetcode - 200
class Solution {
public:
    void dfs(int i,int j,int n,int m,vector<vector<char>>& grid,vector<vector<bool>> &visited,vector<int> &delrow,vector<int> &delcol)
    {
        for(int k=0;k<4;k++)
        {
            int nrow = i+delrow[k];
            int ncol = j+delcol[k];
            if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && !visited[nrow][ncol] && grid[nrow][ncol]=='1')
            {
                visited[nrow][ncol] = true;
                dfs(nrow,ncol,n,m,grid,visited,delrow,delcol);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // optimal -> dfs or bfs tc-o(4*n*m) sc-o(n*m)
        int ans = 0,n=grid.size(),m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,1,0,-1};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] && grid[i][j]=='1')
                {
                    ans++;
                    visited[i][j] = true;
                    dfs(i,j,n,m,grid,visited,delrow,delcol);
                }
            }
        }
        return ans;
    }
};