// minimum coins
// leetcode - 322
class Solution {
public:
    int recursion(int ind,vector<int> &coins,int amount)
    {
        if(ind == 0)
        {
            if(amount%coins[ind]==0)
                return amount/coins[ind];
            return 1e9;
        }
        int take = 1e9,not_take = 1e9;
        if(coins[ind]<=amount)
            take = 1+recursion(ind,coins,amount-coins[ind]);
        not_take = recursion(ind-1,coins,amount);
        return min(take,not_take);
    }
    int memoization(int ind,vector<int> &coins,int amount,vector<vector<int>> &dp)
    {
        if(ind == 0)
        {
            if(amount%coins[ind]==0)
                return amount/coins[ind];
            return 1e9;
        }

        if(dp[ind][amount]!=-1)
            return dp[ind][amount];
        int take = 1e9,not_take=1e9;
        if(coins[ind]<=amount)
            take = 1+memoization(ind,coins,amount-coins[ind],dp);
        not_take = memoization(ind-1,coins,amount,dp);
        return dp[ind][amount] = min(take,not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        // recursion
        /*int n = coins.size();
        int ans =  recursion(n-1,coins,amount);
        if(ans >= 1e9)
            return -1;
        return ans;*/
        // memoization
        /*int n = coins.size();
        int ans = 1e9;
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        ans = memoization(n-1,coins,amount,dp);
        if(ans>=1e9)
            return -1;
        return ans;*/

        // tabulation
        /*int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        for(int i=0;i<=amount;i++)
        {
            if(i%coins[0]==0)
                dp[0][i] = i/coins[0];
            else dp[0][i] = 1e9;
        }
        for(int ind=1;ind<n;ind++)
        {
            for(int am=0;am<=amount;am++)
            {
                int take = 1e9,not_take=1e9;
                if(coins[ind]<=am)
                    take = 1+dp[ind][am-coins[ind]];
                not_take = dp[ind-1][am];
                dp[ind][am] = min(take,not_take);
            }
        }
        if(dp[n-1][amount]>=1e9)
            return -1;
        return dp[n-1][amount];*/

        //space optimization
        int n = coins.size();
        vector<int> prev(amount+1,-1);
        for(int i=0;i<=amount;i++)
        {
            if(i%coins[0]==0)
                prev[i] = i/coins[0];
            else prev[i] = 1e9;
        }
        for(int ind=1;ind<n;ind++)
        {
            vector<int> cur(amount+1,-1);
            for(int am=0;am<=amount;am++)
            {
                int take = 1e9,not_take=1e9;
                if(coins[ind]<=am)
                    take = 1+cur[am-coins[ind]];
                not_take = prev[am];
                cur[am] = min(take,not_take);
            }
            prev = cur;
        }
        if(prev[amount]>=1e9)
            return -1;
        return prev[amount];
    }
};