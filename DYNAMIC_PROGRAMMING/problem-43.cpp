// largest divisible subset
// leetcode - 368
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // sorting, printing LIS variation problem
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1),hash(n);
        for(int i=0;i<n;i++)
        {
            hash[i] = i;
        }
        int maxi = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if((nums[i]%nums[j])==0)
                {
                    if(dp[j]+1>dp[i])
                    {
                        dp[i] = dp[j]+1;
                        hash[i] = j;
                    }
                    if(dp[maxi]<dp[i])
                        maxi = i;
                }
            }
        }
        vector<int> ans;
        int ind = maxi;
        while(hash[ind]!=ind)
        {
            ans.push_back(nums[ind]);
            ind = hash[ind];
        }
        ans.push_back(nums[ind]);
        return ans;
    }
};