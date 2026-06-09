// longest increasing subsequence
// leetcode - 300
class Solution {
public:
    int recursion(int ind,int prev,vector<int> &nums)
    {
        if(ind==nums.size())
            return 0;
        int len = recursion(ind+1,prev,nums);
        if(prev==-1 || nums[prev]<nums[ind])
            len = max(len,1+recursion(ind+1,ind,nums));
        return len;
    }
    int memoization(int ind,int prev,vector<int> &nums,vector<vector<int>> &dp)
    {
        if(ind==nums.size())
            return 0;
        if(dp[ind][prev+1]!=-1)
            return dp[ind][prev+1];
        int len = memoization(ind+1,prev,nums,dp);
        if(prev==-1 || nums[prev]<nums[ind])
            len = max(len,1+memoization(ind+1,ind,nums,dp));
        return dp[ind][prev+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        // recursion
        /*int n = nums.size();
        return recursion(0,-1,nums);*/

        // memoization
        /*int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n+1,-1));
        return memoization(0,-1,nums,dp);*/

        // tabulation
        /*int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int prev=n-1;prev>=-1;prev--)
            {
                int len = dp[ind+1][prev+1];
                if(prev==-1 || nums[prev]<nums[ind])
                    len = max(len,1+dp[ind+1][ind+1]);
                dp[ind][prev+1] = len;
            }
        }
        return dp[0][0];*/

        // space optimization
        /*int n = nums.size();
        vector<int> dp(n+1,0),cur(n+1,0);
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int prev=n-1;prev>=-1;prev--)
            {
                int len = dp[prev+1];
                if(prev==-1 || nums[prev]<nums[ind])
                    len = max(len,1+dp[ind+1]);
                cur[prev+1] = len;
            }
            dp = cur;
        }
        return dp[0];*/

        // tabulation told by striver (this solution is required to trace back and print the lis)
        int n = nums.size();
        vector<int> dp(n,1);
        int maxi = 1;
        for(int ind=0;ind<n;ind++)
        {
            for(int prev=0;prev<ind;prev++)
            {
                if(nums[prev]<nums[ind]){
                    dp[ind] = max(dp[ind],dp[prev]+1);
                    maxi = max(maxi,dp[ind]);
                }
            }
        }
        return maxi;
    }
};