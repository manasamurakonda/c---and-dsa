// triangle 
// leetcode - 120
class Solution {
public:
    int recursion(int row,int col,int n,vector<vector<int>>& triangle)
    {
        if(row==n)
            return 0;
        int left =0,right = 0;
        left = recursion(row+1,col,n,triangle);
        right = recursion(row+1,col+1,n,triangle);
        return min(left,right)+triangle[row][col];
    }
    int memoization(int row,int col,int n,vector<vector<int>>& triangle,vector<vector<int>> &dp)
    {
        if(row==n-1)
            return triangle[row][col];
        if(dp[row][col]!=-1)
            return dp[row][col];
        int left =0,right = 0;
        left = memoization(row+1,col,n,triangle,dp);
        right = memoization(row+1,col+1,n,triangle,dp);
        return dp[row][col] = min(left,right)+triangle[row][col];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        // recursion tc-o(n*n) sc-o(n+n*n)
        /*int n = triangle.size();
        return recursion(0,0,n,triangle);*/

        // memoization tc-o(n*n) sc-o(n+n*n)
        /*int n = triangle.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return memoization(0,0,n,triangle,dp);*/

        // tabulation tc-o(n*n) sc-o(n*n)
        /*int n = triangle.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        for(int row=n-1;row>=0;row--)
        {
            for(int col=row;col>=0;col--)
            {
                if(row==n-1)
                    dp[row][col] = triangle[row][col];
                else{
                    int left =0,right = 0;
                    left = dp[row+1][col];
                    right = dp[row+1][col+1];
                    dp[row][col] = min(left,right)+triangle[row][col];
                }
            }
        }
        return dp[0][0];*/

        // space optimization tc-o(n*n) sc-o(2n)
        int n = triangle.size();
        vector<int> dp(n,-1);
        for(int row=n-1;row>=0;row--)
        {
            vector<int> temp(n,-1);
            for(int col=row;col>=0;col--)
            {
                if(row==n-1)
                    temp[col] = triangle[row][col];
                else{
                    int left =0,right = 0;
                    left = dp[col];
                    right = dp[col+1];
                    temp[col] = min(left,right)+triangle[row][col];
                }
            }
            dp = temp;
        }
        return dp[0];
    }
};