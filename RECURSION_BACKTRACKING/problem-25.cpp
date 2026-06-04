// GFG - rat in a maze
class Solution {
  public:
    void compute(int row,int col,int n,vector<string> &ans,string &temp,vector<vector<int>>& maze,vector<vector<int>> &flag)
    {
        if(row == n-1 && col == n-1)
        {
            ans.push_back(temp);
            return;
        }
        
        if(row+1<n && maze[row+1][col]==1 && flag[row+1][col]==0)
        {
            flag[row+1][col]=1;
            temp.push_back('D');
            compute(row+1,col,n,ans,temp,maze,flag);
            temp.pop_back();
            flag[row+1][col]=0;
        }
        if(col-1>=0 && maze[row][col-1]==1 && flag[row][col-1]==0)
        {
            flag[row][col-1]=1;
            temp.push_back('L');
            compute(row,col-1,n,ans,temp,maze,flag);
            temp.pop_back();
            flag[row][col-1]=0;
        }
        if(col+1<n && maze[row][col+1]==1 && flag[row][col+1]==0)
        {
            flag[row][col+1]=1;
            temp.push_back('R');
            compute(row,col+1,n,ans,temp,maze,flag);
            temp.pop_back();
            flag[row][col+1]=0;
        }
        if(row-1>=0 && maze[row-1][col]==1 && flag[row-1][col]==0)
        {
            flag[row-1][col]=1;
            temp.push_back('U');
            compute(row-1,col,n,ans,temp,maze,flag);
            temp.pop_back();
            flag[row-1][col]=0;
        }
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // optimal -> backtracking (trying all possibilities)
        int n = maze.size();
        vector<string> ans;
        vector<vector<int>> flag(n,vector<int>(n,0));
        string temp = "";
        flag[0][0]= 1;
        compute(0,0,n,ans,temp,maze,flag);
        return ans;
    }
};