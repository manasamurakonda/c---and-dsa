// subarray sum equals k leetcode -560
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // brute ->generating all subarrays
        /*int n=nums.size();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++)
            {
                sum=sum+nums[j];
                if(sum==k)
                    ans++;
            }
        }
        return ans;*/

        // optimal -> prefix sum using hashing
        int n= nums.size();
        unordered_map<int,int> m;
        int sum=0,ans=0;
        m[0] = 1;
        for(int i=0;i<n;i++)
        {
            sum = sum+nums[i];
            if(m.find(sum-k)!=m.end())
            {
                ans=ans+m[sum-k];
            }
            m[sum]++;
        }
        return ans;
    }
};