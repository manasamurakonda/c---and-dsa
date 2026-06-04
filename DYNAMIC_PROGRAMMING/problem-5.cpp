// Maximum Sum of Non-Adjacent Elements | House Robber
// leetcode - 198
class Solution {
public:
    int recursion(vector<int> &nums,int ind,int money)
    {
        if(ind<=-1)
            return money;
        money = money + nums[ind];
        int left = recursion(nums,ind-2,money);
        money = money - nums[ind];
        int right = recursion(nums,ind-1,money);
        return max(left,right);
    }
    int memoization(vector<int> &nums,int ind,vector<int> &dp)
    {
        if(ind<0)
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        int left = nums[ind] + memoization(nums,ind-2,dp);
        int right = memoization(nums,ind-1,dp);
        return dp[ind] = max(left,right);
    }
    int rob(vector<int>& nums) {
        // recursion
        /*int n = nums.size();
        return recursion(nums,n-1,0);*/

        // memoization tc-o(n) sc-o(2n)
        /*int n =nums.size();
        vector<int> dp(n,-1);
        return memoization(nums,n-1,dp);*/

        // tabulation tc-o(n) sc-o(n)
        /*int n = nums.size();
        vector<int> dp(n,-1);
        dp[0] = nums[0];
        for(int i=1;i<n;i++)
        {
            int left = nums[i],right = INT_MIN;
            if(i-2>=0)
                left = nums[i]+dp[i-2];
            right = dp[i-1];
            dp[i] = max(left,right);
        }
        return dp[n-1];*/

        // space optimization tc-o(n) sc-o(1)
        int n = nums.size();
        int prev1 = nums[0],prev2 = 0;
        for(int i=1;i<n;i++)
        {
            int left = nums[i],right = INT_MIN;
            if(i-2>=0)
                left = nums[i]+prev2;
            right = prev1;
            prev2 = prev1;
            prev1 = max(left,right);
        }
        return prev1;
    }
};