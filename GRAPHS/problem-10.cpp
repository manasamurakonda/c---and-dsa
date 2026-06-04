// GFG - Number of Distinct Islands
class Solution {
  public:
    void dfs(int row,int col,int n,int m,int row0,int col0,vector<vector<int>>& grid,vector<vector<bool>> &visited,vector<pair<int,int>> &temp,vector<int> &delrow,vector<int> &delcol)
    {
        visited[row][col] = true;
        temp.push_back({row-row0,col-col0});
        for(int i=0;i<4;i++)
        {
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];
            if(nrow<n && ncol<m && nrow>=0 && ncol>=0 && !visited[nrow][ncol] && grid[nrow][ncol]==1)
            {
                dfs(nrow,ncol,n,m,row0,col0,grid,visited,temp,delrow,delcol);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // optimal -> store the shapes somehow(maybe take a base) tc-o(5nm) sc-o(2nm)
        int n = grid.size(),m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool> (m,false));
        map<vector<pair<int,int>>,int> mp;
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,1,0,-1};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                vector<pair<int,int>> temp;
                if(!visited[i][j] && grid[i][j]==1)
                {
                    dfs(i,j,n,m,i,j,grid,visited,temp,delrow,delcol);
                    mp[temp]++;
                }
            }
        }
        return mp.size();
    }
};

