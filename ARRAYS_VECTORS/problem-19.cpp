// set matrix zeros leetcode-73
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // brute -> nested loops
        /*int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> ans(n,vector<int> (m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans[i][j] = matrix[i][j];
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j] == 0)
                {
                    for(int k=0;k<n;k++)
                    {
                        ans[k][j] = 0;
                    }
                    for(int k=0;k<m;k++)
                    {
                        ans[i][k] = 0;
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                matrix[i][j] = ans[i][j];
            }
        }*/
        //better -> use two maps to mark or store row and col numbers
        /*int n = matrix.size();
        int m = matrix[0].size();
        unordered_map<int,int> row;
        unordered_map<int,int> col;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j] == 0)
                {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(row.find(i)!=row.end())
            {
                for(int j=0;j<m;j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            if(col.find(i)!=col.end())
            {
                for(int j=0;j<n;j++)
                {
                    matrix[j][i] = 0;
                }
            }
        }*/

        // brute-2 ->mark row and column with other number
        /*int n = matrix.size(),m = matrix[0].size();
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(matrix[i][j] == 0)
                {
                    for(int k=0;k<n;k++)
                    {
                        if(matrix[k][j]!=0)
                            matrix[k][j] = INT_MAX;
                    }
                    for(int k=0;k<m;k++)
                    {
                        if(matrix[i][k]!=0)
                            matrix[i][k] = INT_MAX;
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j] == INT_MAX){
                    matrix[i][j] = 0;
                }
            }
        }*/
        // optimal - > use 0th row and 0th column to mark rows
        int n=matrix.size(),m=matrix[0].size();
        int col0 = 1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    if(j==0)
                        col0=0;
                    else
                        matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[0][j] ==0 || matrix[i][0] ==0)
                    matrix[i][j] = 0;
            }
        }
        if(matrix[0][0] ==0)
        {
            for(int i=0;i<m;i++)
            {
                matrix[0][i] = 0;
            }
        }
        if(col0 ==0)
        {
            for(int i=0;i<n;i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};