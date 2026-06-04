// GFG - Subset Sum Problem
class Solution {
  public:
    bool recursion(int ind,int n,vector<int> &arr,int sum)
    {
        if(ind==n)
        {
            if(sum==0)
                return true;
            else
                return false;
        }
        bool pick = false,notpick = false;
        if(sum>=arr[ind])
            pick = recursion(ind+1,n,arr,sum-arr[ind]);
        notpick = recursion(ind+1,n,arr,sum);
        
        return (pick || notpick);
    }
    bool memoization(int ind,int n,vector<int> &arr,int sum,vector<vector<int>> &dp)
    {
        if(ind==n)
        {
            if(sum==0)
                return true;
            else
                return false;
        }
        if(dp[ind][sum]!=-1)
            return dp[ind][sum];
        bool pick = false,notpick = false;
        if(sum>=arr[ind])
            pick = memoization(ind+1,n,arr,sum-arr[ind],dp);
        notpick = memoization(ind+1,n,arr,sum,dp);
        
        return dp[ind][sum] = (pick || notpick);
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // recursion tc-o(2^n) sc-o(n)
        /*int n = arr.size();
        return recursion(0,n,arr,sum);*/
        
        // memoization tc-o(n*sum) sc-o(n*sum)+o(n)
        /*int n = arr.size();
        vector<vector<int>> dp(n,vector<int> (sum+1,-1));
        return memoization(0,n,arr,sum,dp);*/
        
        // tabulation tc-o(n*sum) sc-o(n*sum)
        /*int n = arr.size();
        vector<vector<bool>> dp(n,vector<bool> (sum+1,0));
        dp[n-1][arr[n-1]] = true;
        for(int i=0;i<n;i++)
        {
            dp[i][0] = 1;
        }
        for(int ind=n-2;ind>=0;ind--)
        {
            for(int sum1 = 0;sum1<=sum;sum1++)
            {
                bool pick = false,notpick = false;
                if(sum1>=arr[ind])
                    pick = dp[ind+1][sum1-arr[ind]];
                notpick = dp[ind+1][sum1];
                dp[ind][sum1] = (pick || notpick);
            }
        }
        return dp[0][sum];*/
        
        // space optimization tc-o(n*sum) sc-o(2*sum)
        int n = arr.size();
        vector<bool> dp(sum+1,0);
        dp[arr[n-1]] = true;
        dp[0] = 1;
        for(int ind=n-2;ind>=0;ind--)
        {
            vector<bool> temp(sum+1,0);
            for(int sum1 = 0;sum1<=sum;sum1++)
            {
                bool pick = false,notpick = false;
                if(sum1>=arr[ind])
                    pick = dp[sum1-arr[ind]];
                notpick = dp[sum1];
                temp[sum1] = (pick || notpick);
            }
            dp = temp;
        }
        return dp[sum];
    }
};