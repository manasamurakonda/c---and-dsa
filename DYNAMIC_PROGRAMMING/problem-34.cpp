// Wildcard Matching
// leetcode - 44
class Solution {
public:
    bool recursion(int ind1,int ind2,string &s,string &p)
    {
        if(ind1<0 && ind2<0)
            return true;
        if(ind1>=0 && ind2<0)
            return false;
        if(ind1<0 && ind2>=0)
        {
            while(ind2>=0)
            {
                if(p[ind2]!='*')
                    return false;
                ind2--;
            }
            return true;
        }

        if(s[ind1]==p[ind2] || p[ind2]=='?')
            return recursion(ind1-1,ind2-1,s,p);
        if(p[ind2]=='*')
            return (recursion(ind1,ind2-1,s,p) || recursion(ind1-1,ind2,s,p));
        return false;
    }
    bool memoization(int ind1,int ind2,string &s,string &p,vector<vector<int>> &dp)
    {
        if(ind1<0 && ind2<0)
            return true;
        if(ind1>=0 && ind2<0)
            return false;
        if(ind1<0 && ind2>=0)
        {
            while(ind2>=0)
            {
                if(p[ind2]!='*')
                    return false;
                ind2--;
            }
            return true;
        }
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];
        
        if(s[ind1]==p[ind2] || p[ind2]=='?')
            return dp[ind1][ind2] = memoization(ind1-1,ind2-1,s,p,dp);
        if(p[ind2]=='*')
            return dp[ind1][ind2] = (memoization(ind1-1,ind2,s,p,dp) || memoization(ind1,ind2-1,s,p,dp));
        return dp[ind1][ind2] = false;
    }
    bool isMatch(string s, string p) {
        // recursion
        /*int n1 = s.size(),n2 = p.size();
        return recursion(n1-1,n2-1,s,p);*/

        // memoization
        /*int n1 = s.size(),n2 = p.size();
        vector<vector<int>> dp(n1,vector<int> (n2,-1));
        return memoization(n1-1,n2-1,s,p,dp);*/

        // tabulation
        /*int n1 = s.size(),n2 = p.size();
        vector<vector<int>> dp((n1+1),vector<int> (n2+1,-1));
        for(int ind1=1;ind1<=n1;ind1++)
            dp[ind1][0] = 0;
        for(int ind2=1;ind2<=n2;ind2++)
        {
            int x = ind2;
            bool flag = true;
            while(x>=1)
            {
                if(p[x-1]!='*'){
                    dp[0][ind2] = 0;
                    flag = false;
                    break;
                }
                x--;
            }
            if(flag)
                dp[0][ind2] = 1;
        }
        dp[0][0] = 1;
        for(int ind1=1;ind1<=n1;ind1++)
        {
            for(int ind2=1;ind2<=n2;ind2++)
            {
                if(s[ind1-1]==p[ind2-1] || p[ind2-1]=='?')
                    dp[ind1][ind2] = dp[ind1-1][ind2-1];
                else if(p[ind2-1]=='*')
                    dp[ind1][ind2] = (dp[ind1-1][ind2] || dp[ind1][ind2-1]);
                else dp[ind1][ind2] = 0;
            }
        }
        return dp[n1][n2];*/

        // space optimization
        int n1 = s.size(),n2 = p.size();
        vector<int> prev(n2+1,-1),cur(n2+1,-1);
        for(int ind2=1;ind2<=n2;ind2++)
        {
            int x = ind2;
            bool flag = true;
            while(x>=1)
            {
                if(p[x-1]!='*'){
                    prev[ind2] = 0;
                    flag = false;
                    break;
                }
                x--;
            }
            if(flag)
                prev[ind2] = 1;
        }
        prev[0] = 1;
        cur = prev;
        for(int ind1=1;ind1<=n1;ind1++)
        {
            if(ind1>0)
                cur[0] = 0;
            for(int ind2=1;ind2<=n2;ind2++)
            {
                if(s[ind1-1]==p[ind2-1] || p[ind2-1]=='?')
                    cur[ind2] = prev[ind2-1];
                else if(p[ind2-1]=='*')
                    cur[ind2] = (prev[ind2] || cur[ind2-1]);
                else cur[ind2] = 0;
            }
            prev = cur;
        }
        return prev[n2];
    }
};