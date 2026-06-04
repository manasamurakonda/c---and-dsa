// rotten oranges
// leetcode - 994
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // optimal -> multi source bfs tc-o(3*n*m) sc-o(2*n*m)
        int n = grid.size(),m=grid[0].size(),ans=0;
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(n,vector<bool> (m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2){
                    visited[i][j] = true;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty())
        {
            int sz = q.size();
            ans++;
            for(int i=0;i<sz;i++)
            {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                vector<int> delrow = {-1,0,1,0};
                vector<int> delcol = {0,1,0,-1};
                for(int j=0;j<4;j++)
                {
                    int nrow = row+delrow[j];
                    int ncol = col+delcol[j];
                    if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && visited[nrow][ncol]==false && grid[nrow][ncol]==1){
                        visited[nrow][ncol] = true;
                        q.push({nrow,ncol});
                    }
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j]==false && grid[i][j]==1)
                    return -1;
            }
        }
        ans = max(0,ans-1);
        return ans;
    }
};