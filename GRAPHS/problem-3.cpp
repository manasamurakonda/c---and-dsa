// flood fill
// leetcode - 733
class Solution {
public:
    void dfs(int original,int row,int col,int n,int m,vector<vector<int>>& image,int color,vector<vector<bool>> &visited,vector<int> &delrow,vector<int> &delcol)
    {
        image[row][col] = color;
        for(int i=0;i<4;i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && !visited[nrow][ncol] && image[nrow][ncol]==original)
            {
                visited[nrow][ncol] = true;
                dfs(original,nrow,ncol,n,m,image,color,visited,delrow,delcol);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // optimal -> dfs or bfs tc-o(n*m) sc-o(n*m)
        int n = image.size(),m=image[0].size();
        vector<vector<bool>> visited(n,vector<bool> (m,false));
        visited[sr][sc] = true;
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,1,0,-1};
        int original = image[sr][sc];
        dfs(original,sr,sc,n,m,image,color,visited,delrow,delcol);
        return image;
    }
};