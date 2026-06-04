// tuf - Frog jump with K distances
class Solution {
public:
    int recursion(vector<int> &heights,int k,int ind)
    {
        if(ind == 0)
            return 0;
        int mini = INT_MAX;
        for(int i=1;i<=k;i++)
        {
            if(ind-i<0)
                break;
            mini = min(mini,recursion(heights,k,ind-i)+abs(heights[ind-i]-heights[ind]));
        }
        return mini;
    }
    int memoization(vector<int> &heights,int k,int ind,vector<int> &dp)
    {
        if(ind == 0)
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        int mini = INT_MAX;
        for(int i=1;i<=k;i++)
        {
            if(ind-i<0)
                break;
            mini = min(mini,memoization(heights,k,ind-i,dp)+abs(heights[ind-i]-heights[ind]));
        }
        return dp[ind] = mini;
    }
    int frogJump(vector<int>& heights, int k) {
        // recursion
        /*int n = heights.size();
        return recursion(heights,k,n-1);*/

        // memoization tc-o(n) sc-o(2n)
        /*int n = heights.size();
        vector<int> dp(n,-1);
        return memoization(heights,k,n-1,dp);*/

        //tabulation tc-o(n) sc-o(n)
        int n = heights.size();
        vector<int> dp(n,-1);
        dp[0] = 0;
        for(int ind=1;ind<n;ind++)
        {
            int mini = INT_MAX;
            for(int i = 1;i<=k;i++)
            {
                if(ind-i<0)
                    break;
                mini = min(mini,dp[ind-i]+abs(heights[ind-i]-heights[ind]));
            }
            dp[ind] = mini;
        }
        return dp[n-1];
    }
};