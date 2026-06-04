// shortest path in a binary matrix
// leetcode - 1091
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // optimal -> bfs tc-o(n^2) sc-o(n^2)
        if(grid[0][0]==1)
            return -1;
        int n = grid.size();
        queue<pair<int,pair<int,int>>> q;
        vector<vector<bool>> visited(n, vector<bool> (n,false));
        q.push({1,{0,0}});
        visited[0][0] = true;
        vector<int> delrow = {-1,-1,-1,0,0,1,1,1};
        vector<int> delcol = {-1,0,1,-1,1,-1,0,1};
        while(!q.empty())
        {
            int dist = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            if(row == n-1 && col == n-1)
                        return dist;
            for(int i=0;i<8;i++)
            {
                int newrow = row + delrow[i];
                int newcol = col + delcol[i];
                if(newrow>=0 && newrow<n && newcol>=0 && newcol<n && grid[newrow][newcol]==0 && !visited[newrow][newcol])
                {
                    q.push({dist+1,{newrow,newcol}});
                    visited[newrow][newcol] = true;
                }
            }
        }
        return -1;
    }
};