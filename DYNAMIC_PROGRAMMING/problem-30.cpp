// minimum no.of insertions or deletions to convert one string into another
// leetcode - 583
// do (n1-lcs(s1,s2))+(n2-lcs(s1,s2))
class Solution {
public:
    int recursion(int ind1,int ind2,string &word1,string &word2)
    {
        if(ind1<0 || ind2<0)
            return 0;
        if(word1[ind1]==word2[ind2])
            return 1 + recursion(ind1-1,ind2-1,word1,word2);
        return max(recursion(ind1-1,ind2,word1,word2),recursion(ind1,ind2-1,word1,word2));
    }
    int memoization(int ind1,int ind2,string &word1,string &word2,vector<vector<int>> &dp)
    {
        if(ind1<0 || ind2<0)
            return 0;
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];
        if(word1[ind1]==word2[ind2])
            return dp[ind1][ind2] =  1 + memoization(ind1-1,ind2-1,word1,word2,dp);
        return dp[ind1][ind2] =  max(memoization(ind1-1,ind2,word1,word2,dp),memoization(ind1,ind2-1,word1,word2,dp));
    }
    int minDistance(string word1, string word2) {
        // recursion
        /*int n1 = word1.size(),n2 = word2.size();
        int cnt = recursion(n1-1,n2-1,word1,word2);
        return (n1-cnt)+(n2-cnt);*/

        // memoization
        /*int n1 = word1.size(),n2 = word2.size();
        vector<vector<int>> dp(n1,vector<int> (n2,-1));
        int cnt = memoization(n1-1,n2-1,word1,word2,dp);
        return (n1-cnt)+(n2-cnt);*/

        // tabulation
        /*int n1 = word1.size(),n2 = word2.size();
        vector<vector<int>> dp(n1+1,vector<int> (n2+1,-1));
        for(int ind=0;ind<=n1;ind++)
            dp[ind][0] = 0;
        for(int ind=0;ind<=n2;ind++)
            dp[0][ind] = 0;
        for(int ind1=1;ind1<=n1;ind1++)
        {
            for(int ind2=1;ind2<=n2;ind2++)
            {
                if(word1[ind1-1]==word2[ind2-1])
                    dp[ind1][ind2] =  1 + dp[ind1-1][ind2-1];
                else dp[ind1][ind2] =  max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
            }
        }
        return (n1-dp[n1][n2])+(n2-dp[n1][n2]);*/

        // space optimization
        int n1 = word1.size(),n2 = word2.size();
        vector<int> prev(n2+1,-1),cur(n2+1,-1);
        for(int ind=0;ind<=n2;ind++)
            prev[ind] = 0;
        cur = prev;
        for(int ind1=1;ind1<=n1;ind1++)
        {
            for(int ind2=1;ind2<=n2;ind2++)
            {
                if(word1[ind1-1]==word2[ind2-1])
                    cur[ind2] =  1 + prev[ind2-1];
                else cur[ind2] =  max(prev[ind2],cur[ind2-1]);
            }
            prev = cur;
        }
        return (n1-prev[n2])+(n2-prev[n2]);
    }
};