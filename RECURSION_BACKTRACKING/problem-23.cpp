// sudoku solver
// leetcode - 37
class Solution {
public:
    bool check(char k,int row,int col,vector<vector<char>>& board)
    {
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==k || board[i][col]==k)
                return false;
        }
        int low = 0,high = 0;
        if(row<3)
        {
            low = 0,high = 3;
        }
        else if(row<6)
        {
            low = 3,high = 6;
        }
        else{
            low = 6,high = 9;
        }
        int lowc = 0,highc = 0;
        if(col<3)
        {
            lowc = 0,highc = 3;
        }
        else if(col<6)
        {
            lowc = 3,highc = 6;
        }
        else{
            lowc = 6,highc = 9;
        }
        for(int i=low;i<high;i++)
        {
            for(int j=lowc;j<highc;j++)
            {
                if(board[i][j]==k)
                    return false;
            }
        }
        return true;
    }
    bool compute(vector<vector<char>>& board)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j] == '.')
                {
                    for(char k = '1';k<='9';k++)
                    {
                        if(check(k,i,j,board))
                        {
                            board[i][j] = k;
                            if(compute(board))
                                return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        // brute -> recursion , for loop

        // optimal -> recursion, hashing (pending)
        compute(board);
    }
};