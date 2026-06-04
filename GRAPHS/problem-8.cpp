// Surrounded Regions
// leetcode - 130
class Solution {
public:
    void dfs(int row,int col,int n,int m,vector<vector<char>>& board,vector<vector<bool>> &visited,vector<int> &delrow,vector<int> &delcol)
    {
        visited[row][col] = true;
        for(int i=0;i<4;i++)
        {
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && visited[nrow][ncol]==false && board[nrow][ncol]=='O')
            dfs(nrow,ncol,n,m,board,visited,delrow,delcol);
        }
    }
    void solve(vector<vector<char>>& board) {
        // optimal -> traverse edges of the grid tc-o(5nm+n+m) sc-o(2nm)
        int n = board.size(),m = board[0].size();
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,1,0,-1};
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O' && visited[i][0]==false)
                dfs(i,0,n,m,board,visited,delrow,delcol);
            
            if(board[i][m-1]=='O' && visited[i][m-1]==false)
                dfs(i,m-1,n,m,board,visited,delrow,delcol);
        }
        
        for(int i=0;i<m;i++)
        {
            if(board[0][i]=='O' && visited[0][i]==false)
                dfs(0,i,n,m,board,visited,delrow,delcol);

            if(board[n-1][i]=='O' && visited[n-1][i]==false)
                dfs(n-1,i,n,m,board,visited,delrow,delcol);
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j]==false && board[i][j]=='O')
                    board[i][j] = 'X';
            }
        }
    }
};