// distinct subsequences
// leetcode - 115
class Solution {
public:
    int recursion(int ind1,int ind2,string &s,string &t)
    {
        if(ind1<0 || ind2<0){
            if(ind2<0)
                return 1;
            return 0;
        }
        if(s[ind1]==t[ind2])
            return (recursion(ind1-1,ind2-1,s,t)+recursion(ind1-1,ind2,s,t));
        else return recursion(ind1-1,ind2,s,t);
    }
    int memoization(int ind1,int ind2,string &s,string &t,vector<vector<int>> &dp)
    {
        if(ind1<0 || ind2<0)
        {
            if(ind2<0)
                return 1;
            return 0;
        }
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];
        if(s[ind1]==t[ind2])
            return dp[ind1][ind2] = (memoization(ind1-1,ind2-1,s,t,dp)+memoization(ind1-1,ind2,s,t,dp));
        else return dp[ind1][ind2] = memoization(ind1-1,ind2,s,t,dp);
    }
    int numDistinct(string s, string t) {
        // recursion
        /*int n1 = s.size(),n2=t.size();
        return recursion(n1-1,n2-1,s,t);*/

        // memoization
        /*int n1 = s.size(),n2=t.size();
        vector<vector<int>> dp(n1,vector<int> (n2,-1));
        return memoization(n1-1,n2-1,s,t,dp);*/

        // tabulation
        /*int n1 = s.size(),n2 = t.size();
        vector<vector<unsigned long long>> dp(n1+1,vector<unsigned long long> (n2+1,-1));
        for(int ind1=0;ind1<=n1;ind1++)
            dp[ind1][0] = 1;
        for(int ind2=1;ind2<=n2;ind2++)
            dp[0][ind2] = 0;
        for(int ind1=1;ind1<=n1;ind1++)
        {
            for(int ind2=1;ind2<=n2;ind2++)
            {
                if(s[ind1-1]==t[ind2-1])
                    dp[ind1][ind2] = (dp[ind1-1][ind2-1]+dp[ind1-1][ind2]);
                else dp[ind1][ind2] = dp[ind1-1][ind2];
            }
        }
        return dp[n1][n2];*/

        // space optimization
        int n1 = s.size(),n2 = t.size();
        vector<unsigned long long> prev(n2+1,0),cur(n2+1,0);
        prev[0] = 1;
        cur[0] = 1;
        for(int ind1=1;ind1<=n1;ind1++)
        {
            for(int ind2=1;ind2<=n2;ind2++)
            {
                if(s[ind1-1]==t[ind2-1])
                    cur[ind2] = (prev[ind2-1]+prev[ind2]);
                else cur[ind2] = prev[ind2];
            }
            prev = cur;
        }
        return prev[n2];
    }
};