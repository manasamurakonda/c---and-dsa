// coin change 2
// leetcode - 518
class Solution {
public:
    int recursion(int ind,vector<int> &coins,int amount)
    {
        if(ind==0)
        {
            if(amount%coins[0]==0)
                return 1;
            return 0;
        }
        int take = 0,not_take =0;
        if(coins[ind]<=amount)
            take = recursion(ind,coins,amount-coins[ind]);
        not_take = recursion(ind-1,coins,amount);
        return take+not_take;
    }
    int memoization(int ind,vector<int> &coins,int amount,vector<vector<int>> &dp)
    {
        if(ind==0)
        {
            if(amount%coins[0]==0)
                return 1;
            return 0;
        }
        if(dp[ind][amount]!=-1)
            return dp[ind][amount];
        int take = 0,not_take=0;
        if(coins[ind]<=amount)
            take = memoization(ind,coins,amount-coins[ind],dp);
        not_take = memoization(ind-1,coins,amount,dp);
        return dp[ind][amount] = take+not_take;
    }
    int change(int amount, vector<int>& coins) {
        // recursion
        /*int n = coins.size();
        return recursion(n-1,coins,amount);*/

        // memoization
        /*int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        return memoization(n-1,coins,amount,dp);*/

        // tabulation
        /*int n = coins.size();
        vector<vector<unsigned long long>> dp(n,vector<unsigned long long>(amount+1,-1));
        for(int i=0;i<=amount;i++)
        {
            if(i%coins[0]==0)
                dp[0][i] = 1;
            else dp[0][i] = 0;
        }

        for(int ind = 1;ind<n;ind++)
        {
            for(int am=0;am<=amount;am++){
                unsigned long long take = 0,not_take=0;
                if(coins[ind]<=am)
                    take = dp[ind][am-coins[ind]];
                not_take = dp[ind-1][am];
                dp[ind][am] = take+not_take;
            }
        }
        return dp[n-1][amount];*/


        // space optimization
        int n = coins.size();
        vector<unsigned long long> dp(amount+1,-1);
        for(int i=0;i<=amount;i++)
        {
            if(i%coins[0]==0)
                dp[i] = 1;
            else dp[i] = 0;
        }

        for(int ind = 1;ind<n;ind++)
        {
            vector<unsigned long long> temp(amount+1,-1);
            for(int am=0;am<=amount;am++){
                unsigned long long take = 0,not_take=0;
                if(coins[ind]<=am)
                    take = temp[am-coins[ind]];
                not_take = dp[am];
                temp[am] = take+not_take;
            }
            dp = temp;
        }
        return dp[amount];
    }
};