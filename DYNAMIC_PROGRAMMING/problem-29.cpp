// minimum insertions to make string palindrome
// leetcode - 1312
// the answer is just n-lcs(s,reverse(s))
class Solution {
public:
    int recursion(int ind1,int ind2,string s1,string s2)
    {
        if(ind1<0 || ind2<0)
            return 0;
        if(s1[ind1]==s2[ind2])
            return 1+recursion(ind1-1,ind2-1,s1,s2);
        return max(recursion(ind1-1,ind2,s1,s2),recursion(ind1,ind2-1,s1,s2));
    }
    int memoization(int ind1,int ind2,string s1,string s2,vector<vector<int>> &dp)
    {
        if(ind1<0 || ind2<0)
            return 0;
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];
        if(s1[ind1]==s2[ind2])
            return dp[ind1][ind2] = 1+memoization(ind1-1,ind2-1,s1,s2,dp);
        return dp[ind1][ind2] = max(memoization(ind1-1,ind2,s1,s2,dp),memoization(ind1,ind2-1,s1,s2,dp));
    }
    int minInsertions(string s) {
        // recursion
        /*int n = s.size();
        string t = s;
        reverse(t.begin(),t.end());
        int cnt = recursion(n-1,n-1,s,t);
        return n-cnt;*/

        // memoization
        /*int n = s.size();
        string t = s;
        reverse(t.begin(),t.end());
        vector<vector<int>> dp(n,vector<int> (n,-1));
        int cnt = memoization(n-1,n-1,s,t,dp);
        return n-cnt;*/

        // tabulation
        /*int n = s.size();
        string t = s;
        reverse(t.begin(),t.end());
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        for(int ind=0;ind<=n;ind++){
            dp[0][ind] = 0;
            dp[ind][0] = 0;
        }
        for(int ind1=1;ind1<=n;ind1++)
        {
            for(int ind2=1;ind2<=n;ind2++)
            {
                if(s[ind1-1]==t[ind2-1])
                    dp[ind1][ind2] = 1+dp[ind1-1][ind2-1];
                else dp[ind1][ind2] = max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
            }
        }
        return n-dp[n][n];*/

        //space optimization
        int n = s.size();
        string t = s;
        reverse(t.begin(),t.end());
        vector<int> prev(n+1,-1),cur(n+1,-1);
        for(int ind=0;ind<=n;ind++){
            prev[ind] = 0;
        }
        cur = prev;
        for(int ind1=1;ind1<=n;ind1++)
        {
            for(int ind2=1;ind2<=n;ind2++)
            {
                if(s[ind1-1]==t[ind2-1])
                    cur[ind2] = 1+prev[ind2-1];
                else cur[ind2] = max(prev[ind2],cur[ind2-1]);
            }
            prev = cur;
        }
        return n-cur[n]; 
    }
};