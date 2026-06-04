// GFG - Perfect Sum Problem | Count subsets with sum K
class Solution {
  public:
    int recursion(int ind,int n,int sum,int &target,vector<int> &arr)
    {
        if(ind == n)
        {
            if(sum == target)
                return 1;
            else return 0;
        }
        if(sum>target)
            return 0;
        int pick =0,notpick =0;
        pick = recursion(ind+1,n,sum+arr[ind],target,arr);
        notpick = recursion(ind+1,n,sum,target,arr);
        
        return pick+notpick;
    }
    int memoization(int ind,int n,int sum,int &target,vector<int> &arr,vector<vector<int>> &dp)
    {
        if(ind == n)
        {
            if(sum == target)
                return 1;
            else return 0;
        }
        if(sum>target)
            return 0;
        if(dp[ind][sum]!=-1)
            return dp[ind][sum];
        int pick =0,notpick =0;
        pick = memoization(ind+1,n,sum+arr[ind],target,arr,dp);
        notpick = memoization(ind+1,n,sum,target,arr,dp);
        
        return dp[ind][sum] = pick+notpick;
    }
    int perfectSum(vector<int>& arr, int target) {
        // recursion tc-o(2^n) sc-o(n)
        /*int n = arr.size();
        return recursion(0,n,0,target,arr);*/
        
        // memoization tc-o(n*target) sc-o(n*target)+o(n)
        /*int n = arr.size();
        vector<vector<int>> dp(n,vector<int> (target+1,-1));
        return memoization(0,n,0,target,arr,dp);*/
        
        // tabulation tc-o(n*target) sc-o(n*target)
        /*int n = arr.size();
        vector<vector<int>> dp(n+1,vector<int> (target+1,-1));
        for(int sum=0;sum<=target;sum++)
        {
            if(sum==target)
                dp[n][sum] = 1;
            else dp[n][sum] = 0;
        }
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int sum=0;sum<=target;sum++)
            {
                int pick =0,notpick =0;
                if(sum+arr[ind]<=target)
                    pick = dp[ind+1][sum+arr[ind]];
                notpick = dp[ind+1][sum];
                dp[ind][sum] = pick+notpick;
            }
        }
        return dp[0][0];*/
        
        // space optimization tc-o(n*target) sc-o(2*target)
        int n = arr.size();
        vector<int> dp(target+1,-1);
        for(int sum=0;sum<=target;sum++)
        {
            if(sum==target)
                dp[sum] = 1;
            else dp[sum] = 0;
        }
        for(int ind=n-1;ind>=0;ind--)
        {
            vector<int> temp(target+1,-1);
            for(int sum=0;sum<=target;sum++)
            {
                int pick =0,notpick =0;
                if(sum+arr[ind]<=target)
                    pick = dp[sum+arr[ind]];
                notpick = dp[sum];
                temp[sum] = pick+notpick;
            }
            dp = temp;
        }
        return dp[0];
    }
};