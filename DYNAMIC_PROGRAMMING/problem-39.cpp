// Best Time to Buy and Sell Stock with Transaction Fee
// leetcode - 714
class Solution {
public:
    int recursion(int ind,bool buy,vector<int> &prices,int fee)
    {
        if(ind==prices.size())
            return 0;
        int profit;
        if(buy)
        {
            profit = -prices[ind]+recursion(ind+1,0,prices,fee);
            profit = max(profit,recursion(ind+1,1,prices,fee));
        }
        else{
            profit = prices[ind]-fee+recursion(ind+1,1,prices,fee);
            profit = max(profit,recursion(ind+1,0,prices,fee));
        }
        return profit;
    }
    int memoization(int ind,bool buy,vector<int> &prices,int fee,vector<vector<int>> &dp)
    {
        if(ind==prices.size())
            return 0;
        if(dp[ind][buy]!=-1)
            return dp[ind][buy];
        int profit;
        if(buy)
        {
            profit = -prices[ind]+memoization(ind+1,0,prices,fee,dp);
            profit = max(profit,memoization(ind+1,1,prices,fee,dp));
        }
        else{
            profit = prices[ind]-fee+memoization(ind+1,1,prices,fee,dp);
            profit = max(profit,memoization(ind+1,0,prices,fee,dp));
        }
        return dp[ind][buy] =  profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        // recursion
        /* return recursion(0,1,prices,fee); */

        // memoization
        /*int n = prices.size();
        vector<vector<int>> dp(n,vector<int> (2,-1));
        return memoization(0,1,prices,fee,dp);*/

        // tabulation
        /*int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int> (2,-1));
        dp[n][0] = 0;
        dp[n][1] = 0;
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy = 0;buy<2;buy++)
            {
                int profit;
                if(buy)
                {
                profit = -prices[ind]+dp[ind+1][0];
                profit = max(profit,dp[ind+1][1]);
                }
                else{
                    profit = prices[ind]-fee+dp[ind+1][1];
                    profit = max(profit,dp[ind+1][0]);
                }
                dp[ind][buy] =  profit;                
            }
        }
        return dp[0][1];*/

        // space optimization
        int n = prices.size();
        vector<int> prev(2,0),cur(2,0);
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy = 0;buy<2;buy++)
            {
                int profit;
                if(buy)
                {
                profit = -prices[ind]+prev[0];
                profit = max(profit,prev[1]);
                }
                else{
                    profit = prices[ind]-fee+prev[1];
                    profit = max(profit,prev[0]);
                }
                cur[buy] =  profit;                
            }
            prev = cur;
        }
        return prev[1];
    }
};