// partition equal subset sum
// leetcode - 416
class Solution {
public:
    bool recursion(int ind,int n,vector<int>& nums,int target,int sum)
    {
        if(ind == n)
        {
            if(sum == target)
                return true;
            return false;
        }

        bool first = recursion(ind+1,n,nums,target,sum+nums[ind]);
        bool second = recursion(ind+1,n,nums,target,sum);

        return (first || second);
    }
    bool memoization(int ind,int n,vector<int>& nums,int target,int sum,vector<vector<int>> &dp)
    {
        if(ind == n)
        {
            if(sum == target/2)
                return true;
            return false;
        }
        if(dp[ind][sum]!=-1)
            return dp[ind][sum];
        bool first = memoization(ind+1,n,nums,target,sum+nums[ind],dp);
        bool second = memoization(ind+1,n,nums,target,sum,dp);

        return dp[ind][sum] = (first || second);
    }
    bool canPartition(vector<int>& nums) {
        // recursion tc-o(2^n) sc-o(n)
        /*int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0)
            return false;
        return recursion(0,n,nums,sum/2,0);*/

        // memoization tc-o(n*sum) sc-o(n*sum)+o(n)
        /*int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0)
            return false;
        vector<vector<int>> dp(n,vector<int> (sum,-1));
        return memoization(0,n,nums,sum/2,0,dp);*/

        //tabulation tc-o(n*sum) sc-o(n*sum)
        /*int n = nums.size();
        int target = accumulate(nums.begin(),nums.end(),0);
        if(target%2!=0)
            return false;
        vector<vector<bool>> dp(n+1,vector<bool> ((target/2)+1,0));
        dp[n][target/2] = true; 
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int sum=0;sum<=target/2;sum++)
            {
                bool first = false;
                if(sum+nums[ind]<=target/2)
                first = dp[ind+1][sum+nums[ind]];
                bool second = dp[ind+1][sum];

                dp[ind][sum] = (first || second);
            }
        }
        return dp[0][0];*/

        // space optimization tc-o(n*sum) sc-o(2*target)
        int n = nums.size();
        int target = accumulate(nums.begin(),nums.end(),0);
        if(target%2!=0)
            return false;
        vector<bool> dp((target/2)+1,0);
        dp[target/2] = true;
        for(int ind=n-1;ind>=0;ind--)
        {
             vector<bool> temp((target/2)+1,0);
            for(int sum=0;sum<=target/2;sum++)
            {
                bool first = false;
                if(sum+nums[ind]<=target/2)
                first = dp[sum+nums[ind]];
                bool second = dp[sum];

                temp[sum] = (first || second);
            }
            dp = temp;
        }
        return dp[0];
    }
};