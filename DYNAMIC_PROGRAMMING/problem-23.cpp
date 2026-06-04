// unbounded knapsack
// GFG - Knapsack with Duplicate Items
class Solution {
  public:
    int recursion(int ind,vector<int> &val,vector<int> &wt,int capacity)
    {
        if(ind==0)
        {
            if(wt[ind]<=capacity)
            {
                return val[ind]*(capacity/wt[ind]);
            }
            return 0;
        }
        
        int pick = 0,not_pick =0;
        if(capacity>=wt[ind])
            pick = val[ind]+recursion(ind,val,wt,capacity-wt[ind]);
        not_pick = recursion(ind-1,val,wt,capacity);
        return max(pick,not_pick);
    }
    int memoization(int ind,vector<int> &val,vector<int> &wt,int capacity,vector<vector<int>> &dp)
    {
        if(ind==0)
        {
            if(wt[ind]<=capacity)
            {
                return val[ind]*(capacity/wt[ind]);
            }
            return 0;
        }
        if(dp[ind][capacity]!=-1)
            return dp[ind][capacity];
        int pick=0,not_pick=0;
        if(capacity>=wt[ind])
            pick = val[ind]+memoization(ind,val,wt,capacity-wt[ind],dp);
        not_pick = memoization(ind-1,val,wt,capacity,dp);
        return dp[ind][capacity] = max(pick,not_pick);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // recursion
        /*int n = val.size();
        return recursion(n-1,val,wt,capacity);*/
        
        // memoization
        /*int n = val.size();
        vector<vector<int>> dp(n,vector<int> (capacity+1,-1));
        return memoization(n-1,val,wt,capacity,dp);*/
        
        // tabulation
        /*int n = val.size();
        vector<vector<int>> dp(n,vector<int> (capacity+1,-1));
        for(int c = 0;c<=capacity;c++)
        {
            if(wt[0]<=c)
                dp[0][c] = val[0]*(c/wt[0]);
            else dp[0][c] = 0;
        }
        for(int ind=1;ind<n;ind++)
        {
            for(int c=0;c<=capacity;c++)
            {
                int pick=0,not_pick=0;
                if(c>=wt[ind])
                    pick = val[ind]+dp[ind][c-wt[ind]];
                not_pick = dp[ind-1][c];
                dp[ind][c] = max(pick,not_pick);
            }
        }
        return dp[n-1][capacity];*/
        
        // space optimization
        int n = val.size();
        vector<int> dp(capacity+1,-1);
        for(int c = 0;c<=capacity;c++)
        {
            if(wt[0]<=c)
                dp[c] = val[0]*(c/wt[0]);
            else dp[c] = 0;
        }
        for(int ind=1;ind<n;ind++)
        {
            vector<int> temp(capacity+1,-1);
            for(int c=0;c<=capacity;c++)
            {
                int pick=0,not_pick=0;
                if(c>=wt[ind])
                    pick = val[ind]+temp[c-wt[ind]];
                not_pick = dp[c];
                temp[c] = max(pick,not_pick);
            }
            dp = temp;
        }
        return dp[capacity];
    }
};