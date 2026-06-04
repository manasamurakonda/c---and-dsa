// longest common subsequence
// leetcode - 1143
class Solution {
public:
    void compute(int ind,string text,int n,string temp,vector<string> &ans)
    {
        if(ind==n)
        {
            ans.push_back(temp);
            return;
        }

        temp.push_back(text[ind]);
        compute(ind+1,text,n,temp,ans);
        temp.pop_back();
        compute(ind+1,text,n,temp,ans);
    }
    int recursion(int ind1,int ind2,string &text1,string &text2)
    {
        if(ind1<0 || ind2<0)
            return 0;
        if(text1[ind1]==text2[ind2])
            return 1+recursion(ind1-1,ind2-1,text1,text2);
        return max(recursion(ind1-1,ind2,text1,text2),recursion(ind1,ind2-1,text1,text2));
    }
    int memoization(int ind1,int ind2,string &text1,string &text2,vector<vector<int>> &dp)
    {
        if(ind1<0 || ind2<0)
            return 0;
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];
        if(text1[ind1]==text2[ind2])
            return dp[ind1][ind2] = 1+memoization(ind1-1,ind2-1,text1,text2,dp);
        return dp[ind1][ind2] = max(memoization(ind1-1,ind2,text1,text2,dp),memoization(ind1,ind2-1,text1,text2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        // very brute recursion
        /*int n1 = text1.size(),n2 = text2.size();
        vector<string> ans1,ans2;
        compute(0,text1,n1,"",ans1);
        compute(0,text2,n2,"",ans2);
        int ans = 0;
        for(int i=0;i<ans1.size();i++)
        {
            for(int j=0;j<ans2.size();j++)
            {
                if(ans1[i]==ans2[j] && ans1[i].size()>ans)
                {
                    ans = ans1[i].size();
                }
            }
        }
        return ans;*/

        // recursion
        /*int n1 = text1.size(),n2 = text2.size();
        return recursion(n1-1,n2-1,text1,text2); */

        // memoization
        /*int n1 = text1.size(),n2=text2.size();
        vector<vector<int>> dp(n1,vector<int> (n2,-1));
        return memoization(n1-1,n2-1,text1,text2,dp);*/

        // tabulation using index shifting
        /*int n1 = text1.size(),n2 = text2.size();
        vector<vector<int>> dp(n1+1,vector<int> (n2+1,-1));
        for(int ind1=0;ind1<=n1;ind1++)
            dp[ind1][0] = 0;
        for(int ind2=0;ind2<=n2;ind2++)
            dp[0][ind2] = 0;
        for(int ind1=1;ind1<=n1;ind1++)
        {
            for(int ind2=1;ind2<=n2;ind2++)
            {
                if(text1[ind1-1]==text2[ind2-1])
                    dp[ind1][ind2] = 1+dp[ind1-1][ind2-1];
                else dp[ind1][ind2] = max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
            }
        }
        return dp[n1][n2];*/

        // space optimization
        int n1 = text1.size(),n2 = text2.size();
        vector<int> prev(n2+1,0),cur(n2+1,0);
        for(int ind1=1;ind1<=n1;ind1++)
        {
            for(int ind2=1;ind2<=n2;ind2++)
            {
                if(text1[ind1-1]==text2[ind2-1])
                    cur[ind2] = 1+prev[ind2-1];
                else cur[ind2] = max(prev[ind2],cur[ind2-1]);
            }
            prev = cur;
        }
        return prev[n2];
    }
};