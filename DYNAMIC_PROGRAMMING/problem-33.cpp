// edit distance
// leetcode - 72
class Solution {
public:
    int recursion(int ind1,int ind2,string &word1,string &word2)
    {
        if(ind1<0)
            return ind2+1;
        if(ind2<0)
            return ind1+1;
        if(word1[ind1]==word2[ind2])
            return recursion(ind1-1,ind2-1,word1,word2);
        int x = 1+recursion(ind1,ind2-1,word1,word2);
        int y = 1+recursion(ind1-1,ind2,word1,word2);
        int z = 1+recursion(ind1-1,ind2-1,word1,word2);
        return min(x,min(y,z));
    }
    int memoization(int ind1,int ind2,string &word1,string &word2,vector<vector<int>> &dp)
    {
        if(ind1<0)
            return ind2+1;
        if(ind2<0)
            return ind1+1;
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];
        if(word1[ind1]==word2[ind2])
            return dp[ind1][ind2] = memoization(ind1-1,ind2-1,word1,word2,dp);
        int x = 1+memoization(ind1,ind2-1,word1,word2,dp);
        int y = 1+memoization(ind1-1,ind2,word1,word2,dp);
        int z = 1+memoization(ind1-1,ind2-1,word1,word2,dp);
        return dp[ind1][ind2] = min(x,min(y,z));
    }
    int minDistance(string word1, string word2) {
        // recursion
        /*int n1 = word1.size(),n2=word2.size();
        return recursion(n1-1,n2-1,word1,word2);*/

        // memoization
        /*int n1 = word1.size(),n2 = word2.size();
        vector<vector<int>> dp(n1,vector<int> (n2,-1));
        return memoization(n1-1,n2-1,word1,word2,dp);*/

        // tabulation
        /*int n1 = word1.size(),n2 = word2.size();
        vector<vector<int>> dp(n1+1,vector<int> (n2+1,-1));
        for(int ind1=0;ind1<=n1;ind1++)
            dp[ind1][0] = ind1;
        for(int ind2=0;ind2<=n2;ind2++)
            dp[0][ind2] = ind2;
        for(int ind1=1;ind1<=n1;ind1++)
        {
            for(int ind2=1;ind2<=n2;ind2++)
            {
                if(word1[ind1-1]==word2[ind2-1])
                    dp[ind1][ind2] = dp[ind1-1][ind2-1];
                else{
                    int x = 1+dp[ind1][ind2-1];
                    int y = 1+dp[ind1-1][ind2];
                    int z = 1+dp[ind1-1][ind2-1];
                    dp[ind1][ind2] = min(x,min(y,z));
                }
            }
        }
        return dp[n1][n2];*/
        
        // space optimization
        int n1 = word1.size(),n2 = word2.size();
        vector<int> prev(n2+1,0),cur(n2+1,0);
        for(int ind2=0;ind2<=n2;ind2++)
            prev[ind2] = ind2;
        for(int ind1=1;ind1<=n1;ind1++)
        {
            cur[0] = ind1;
            for(int ind2=1;ind2<=n2;ind2++)
            {
                if(word1[ind1-1]==word2[ind2-1])
                    cur[ind2] = prev[ind2-1];
                else{
                    int x = 1+cur[ind2-1];
                    int y = 1+prev[ind2];
                    int z = 1+prev[ind2-1];
                    cur[ind2] = min(x,min(y,z));
                }
            }
            prev = cur;
        }
        return prev[n2];
    }
};