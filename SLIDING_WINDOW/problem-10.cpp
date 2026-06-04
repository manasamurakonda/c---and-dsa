// subarrays with k different integers
// leetcode - 992
class Solution {
public:
    int slidingWindowPattern2(vector<int>& nums, int k)
    {
        int n = nums.size(),l=0,r=0,ans=0;
        unordered_map<int,int> m;
        while(r<n)
        {
            m[nums[r]]++;
            while(m.size()>k)
            {
                m[nums[l]]--;
                if(m[nums[l]]==0)
                    m.erase(nums[l]);
                l++;
            }
            ans = ans+(r-l+1);
            r++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // brute -> generating all subarrays
        /*int n = nums.size(),ans=0;
        for(int i=0;i<n;i++)
        {
            unordered_map<int,int> m;
            for(int j=i;j<n;j++)
            {
                m[nums[j]]++;
                if(m.size()>k)
                    break;
                if(m.size()==k)
                    ans++;
            }
        }
        return ans;*/


        // optimal -> sliding window (pattern 3)
        return slidingWindowPattern2(nums,k)-slidingWindowPattern2(nums,k-1);
    }
};