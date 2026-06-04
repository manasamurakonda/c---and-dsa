// 01 matrix
// leetcode - 542
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // brute -> bfs checking for every element in mat tc-o((n*m)^2) sc-o(n*m)
        // optimal -> multisource bfs tc-o(5nm) sc-o(2nm)
        int n = mat.size(),m = mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,INT_MAX));
        vector<vector<bool>> visited(n,vector<bool> (m,false));
        queue<pair<pair<int,int>,int>> q;
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,1,0,-1};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0){
                    ans[i][j] = 0;
                    visited[i][j] = true;
                    q.push({{i,j},0});
                }
            }
        }
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int cnt = q.front().second;
            q.pop();
            ans[r][c] = min(ans[r][c],cnt);
            for(int i=0;i<4;i++)
            {
                int nrow = r+delrow[i];
                int ncol = c+delcol[i];
                if(nrow<n && ncol<m && nrow>=0 && ncol>=0 && !visited[nrow][ncol])
                {
                    visited[nrow][ncol] = true;
                    q.push({{nrow,ncol},cnt+1});
                }
            }
        }
        return ans;
    }
};