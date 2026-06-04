// valid sudoku
// leetcode - 36
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++)
        {
            vector<int> flag(n+1,0);
            for(int j=0;j<m;j++)
            {
                if(board[i][j]!='.'){
                    if(flag[board[i][j]-'0']==1)
                        return false;
                    else flag[board[i][j]-'0'] = 1;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            vector<int> flag(n+1,0);
            for(int j=0;j<m;j++)
            {
                if(board[j][i]!='.'){
                    if(flag[board[j][i]-'0']==1)
                        return false;
                    else flag[board[j][i]-'0'] = 1;
                }
            }
        }

        for(int k=0;k<n;k=k+3)
        {
            vector<int> flag(n+1,0);
            for(int i=k;i<k+3;i++){
                for(int j=0;j<3;j++)
                {
                    if(board[i][j]!='.'){
                        if(flag[board[i][j]-'0']==1)
                            return false;
                        else flag[board[i][j]-'0'] = 1;
                    }
                }
            }

            vector<int> flag1(n+1,0);
            for(int i=k;i<k+3;i++){
                for(int j=3;j<6;j++)
                {
                    if(board[i][j]!='.'){
                        if(flag1[board[i][j]-'0']==1)
                            return false;
                        else flag1[board[i][j]-'0'] = 1;
                    }
                }
            }

            vector<int> flag3(n+1,0);
            for(int i=k;i<k+3;i++){
                for(int j=6;j<9;j++)
                {
                    if(board[i][j]!='.'){
                        if(flag3[board[i][j]-'0']==1)
                            return false;
                        else flag3[board[i][j]-'0'] = 1;
                    }
                }
            }
        }
        return true;
    }
};