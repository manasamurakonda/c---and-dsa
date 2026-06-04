// shortest common supersequence
// leetcode - 1092
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        // use dp table of lcs of two strings and tabulation code for lcs
        int n1 = str1.size(),n2 = str2.size();
        vector<vector<int>> dp(n1+1,vector<int> (n2+1,-1));
        for(int ind=0;ind<=n1;ind++)
            dp[ind][0] = 0;
        for(int ind=0;ind<=n2;ind++)
            dp[0][ind] = 0;
        for(int ind1=1;ind1<=n1;ind1++)
        {
            for(int ind2=1;ind2<=n2;ind2++)
            {
                if(str1[ind1-1]==str2[ind2-1])
                    dp[ind1][ind2] = 1+ dp[ind1-1][ind2-1];
                else dp[ind1][ind2] = max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
            }
        }
        int i=n1,j=n2;
        string ans = "";
        while(i>0 && j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
                ans.push_back(str1[i-1]);
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1])
            {
                ans.push_back(str1[i-1]);
                i--;
            }
            else{
                ans.push_back(str2[j-1]);
                j--;
            }
        }
        while(i>0)
        {
            ans.push_back(str1[i-1]);
            i--;
        }
        while(j>0)
        {
            ans.push_back(str2[j-1]);
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};