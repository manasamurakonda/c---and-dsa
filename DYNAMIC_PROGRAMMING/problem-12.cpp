// minimum falling path sum
// leetcode - 931
class Solution {
public:
    int recursion(int row,int col,int n,int m,vector<vector<int>>& matrix)
    {
        if(row == n-1)
            return matrix[row][col];
        int bot = INT_MAX,bot_right = INT_MAX,bot_left = INT_MAX;
        bot = recursion(row+1,col,n,m,matrix);
        if(col+1<m)
            bot_right = recursion(row+1,col+1,n,m,matrix);
        if(col-1>=0)
            bot_left = recursion(row+1,col-1,n,m,matrix);
        return min(bot,min(bot_left,bot_right))+matrix[row][col];
    }
    int memoization(int row,int col,int n,int m,vector<vector<int>>& matrix,vector<vector<int>> &dp)
    {
        if(row == n-1)
            return matrix[row][col];
        if(dp[row][col]!=-1)
            return dp[row][col];
        int bot = INT_MAX,bot_right = INT_MAX,bot_left = INT_MAX;
        bot = memoization(row+1,col,n,m,matrix,dp);
        if(col+1<m)
            bot_right = memoization(row+1,col+1,n,m,matrix,dp);
        if(col-1>=0)
            bot_left = memoization(row+1,col-1,n,m,matrix,dp);
        return dp[row][col] = min(bot,min(bot_left,bot_right))+matrix[row][col];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // recursion
        /*int n = matrix.size(),m=matrix[0].size();
        int ans = INT_MAX;
        for(int i=0;i<m;i++)
        {
            ans = min(ans,recursion(0,i,n,m,matrix));
        }
        return ans;*/

        // memoization tc-o(n*m) sc-o(n+n*m)
        /*int n = matrix.size(),m=matrix[0].size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n,vector<int> (m,-1));
        for(int i=0;i<m;i++)
        {
            ans = min(ans,memoization(0,i,n,m,matrix,dp));
        }
        return ans;*/

        // tabulation tc-o(n*m) sc-o(n*m)
        /*int n = matrix.size(),m=matrix[0].size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n,vector<int> (m,-1));
        for(int i=0;i<m;i++)
        {
            dp[n-1][i] = matrix[n-1][i];
        }
        for(int row = n-2;row>=0;row--)
        {
            for(int col = m-1;col>=0;col--)
            {
                int bot = INT_MAX,bot_right = INT_MAX,bot_left = INT_MAX;
                bot = dp[row+1][col];
                if(col+1<m)
                    bot_right = dp[row+1][col+1];
                if(col-1>=0)
                    bot_left = dp[row+1][col-1];
                dp[row][col] = min(bot,min(bot_left,bot_right))+matrix[row][col];
            }
        }
        return *min_element(dp[0].begin(),dp[0].end());*/

        // space optimization tc-o(n*m) sc-o(2m)
        int n = matrix.size(),m=matrix[0].size();
        int ans = INT_MAX;
        vector<int> dp(m);
        for(int i=0;i<m;i++)
        {
            dp[i] = matrix[n-1][i];
        }
        for(int row = n-2;row>=0;row--)
        {
            vector<int> temp(m,-1);
            for(int col = m-1;col>=0;col--)
            {
                int bot = INT_MAX,bot_right = INT_MAX,bot_left = INT_MAX;
                bot = dp[col];
                if(col+1<m)
                    bot_right = dp[col+1];
                if(col-1>=0)
                    bot_left = dp[col-1];
                temp[col] = min(bot,min(bot_left,bot_right))+matrix[row][col];
            }
            dp = temp;
        }
        return *min_element(dp.begin(),dp.end());
    }
};