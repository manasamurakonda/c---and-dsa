// Best Time to Buy and Sell Stock III
// leetcode - 123
class Solution {
public:
    int recursion(int ind,bool buy,vector<int> &prices,int cap)
    {
        if(cap==0)
            return 0;
        if(ind==prices.size())
            return 0;
        int profit;
        if(buy)
        {
            profit = -prices[ind]+recursion(ind+1,0,prices,cap);
            profit = max(profit,recursion(ind+1,1,prices,cap));
        }
        else{
            profit = prices[ind]+recursion(ind+1,1,prices,cap-1);
            profit = max(profit,recursion(ind+1,0,prices,cap));
        }
        return profit;
    }
    int memoization(int ind,int buy,vector<int> &prices,int cap,vector<vector<vector<int>>> &dp)
    {
        if(cap==0)
            return 0;
        if(ind==prices.size())
            return 0;
        if(dp[ind][buy][cap]!=-1)
            return dp[ind][buy][cap];
        int profit;
        if(buy)
        {
            profit = -prices[ind]+memoization(ind+1,0,prices,cap,dp);
            profit = max(profit,memoization(ind+1,1,prices,cap,dp));
        }
        else{
            profit = prices[ind]+memoization(ind+1,1,prices,cap-1,dp);
            profit = max(profit,memoization(ind+1,0,prices,cap,dp));
        }
        return dp[ind][buy][cap] = profit;
        
    }
    int maxProfit(vector<int>& prices) {
        // recursion
        /*return recursion(0,1,prices,2);*/

        // memoization
        /*int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int> (2+1,-1)));
        return memoization(0,1,prices,2,dp);*/


        // tabulation
        /*int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int> (2+1,0)));
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<2;buy++)
            {
                for(int cap=1;cap<=2;cap++)
                {
                    int profit;
                    if(buy)
                    {
                        profit = -prices[ind]+dp[ind+1][0][cap];
                        profit = max(profit,dp[ind+1][1][cap]);
                    }
                    else{
                        profit = prices[ind]+dp[ind+1][1][cap-1];
                        profit = max(profit,dp[ind+1][0][cap]);
                    }
                    dp[ind][buy][cap] = profit;                
                }
            }
        }
        return dp[0][1][2];*/

        // space optimization
        int n = prices.size();
        vector<vector<int>> prev(2,vector<int> (2+1,0)),cur(2,vector<int> (2+1,0));
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<2;buy++)
            {
                for(int cap=1;cap<=2;cap++)
                {
                    int profit;
                    if(buy)
                    {
                        profit = -prices[ind]+prev[0][cap];
                        profit = max(profit,prev[1][cap]);
                    }
                    else{
                        profit = prices[ind]+prev[1][cap-1];
                        profit = max(profit,prev[0][cap]);
                    }
                    cur[buy][cap] = profit;                
                }
            }
            prev = cur;
        }
        return prev[1][2];

    }
};