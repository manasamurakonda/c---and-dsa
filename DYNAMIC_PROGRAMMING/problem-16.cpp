// GFG - Minimum sum partition
class Solution {
  public:
    int recursion(int ind,int sum,int n,int &total,vector<int> &arr)
    {
        if(ind == n)
            return abs(total-2*sum);
        
        int pick = INT_MAX,notpick = INT_MAX;
        pick = recursion(ind+1,sum+arr[ind],n,total,arr);
        notpick = recursion(ind+1,sum,n,total,arr);
        return min(pick,notpick);
    }
    int memoization(int ind,int sum,int n,int &total,vector<int> &arr,vector<vector<int>> &dp)
    {
        if(ind == n)
            return abs(total-2*sum);
        if(dp[ind][sum]!=-1)
            return dp[ind][sum];
        int pick = INT_MAX,notpick = INT_MAX;
        pick = memoization(ind+1,sum+arr[ind],n,total,arr,dp);
        notpick = memoization(ind+1,sum,n,total,arr,dp);
        return dp[ind][sum] = min(pick,notpick);
    }
    int minDifference(vector<int>& arr) {
        // recursion tc-o(2^n) sc-o(n)
        /*int n = arr.size();
        int total = accumulate(arr.begin(),arr.end(),0);
        return recursion(0,0,n,total,arr);*/
        
        // memoization tc-o(n*total) sc-o(n*total)+o(n)
        /*int n = arr.size();
        int total = accumulate(arr.begin(),arr.end(),0);
        vector<vector<int>> dp(n,vector<int> (total+1,-1));
        return memoization(0,0,n,total,arr,dp);*/
        
        // tabulation tc-o(n*total) sc-o(n*total)
        /*int n = arr.size();
        int total = accumulate(arr.begin(),arr.end(),0);
        vector<vector<int>> dp(n+1,vector<int> (total+1,-1));
        for(int sum=0;sum<=total;sum++)
        {
            dp[n][sum] = abs(total-2*sum);
        }
        
        for(int ind = n-1;ind>=0;ind--)
        {
            for(int sum = 0;sum<=total;sum++)
            {
                int pick = INT_MAX,notpick = INT_MAX;
                pick = dp[ind+1][sum+arr[ind]];
                notpick = dp[ind+1][sum];
                dp[ind][sum] = min(pick,notpick);
            }
        }
        return dp[0][0];*/
        
        // space optimization tc-o(n*total) sc-o(2*total)
        int n = arr.size();
        int total = accumulate(arr.begin(),arr.end(),0);
        vector<int> dp(total+1,-1);
        for(int sum=0;sum<=total;sum++)
        {
            dp[sum] = abs(total-2*sum);
        }
        
        for(int ind = n-1;ind>=0;ind--)
        {
            vector<int> temp(total+1,-1);
            for(int sum = 0;sum<=total;sum++)
            {
                int pick = INT_MAX,notpick = INT_MAX;
                pick = dp[sum+arr[ind]];
                notpick = dp[sum];
                temp[sum] = min(pick,notpick);
            }
            dp = temp;
        }
        return dp[0];
    }
};
