// binary subarrays with sum
// leetcode-930
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // brute -> generating all subarrays
        /*int n = nums.size(),ans=0,sum=0;
        for(int i=0;i<n;i++)
        {
            sum=0;
            for(int j=i;j<n;j++)
            {
                sum = sum + nums[j];
                if(sum==goal)
                {
                    ans++;
                }
                if(sum> goal)
                    break;
            }
        }
        return ans;*/


        // optimal -> sliding window (pattern 3)
        int n = nums.size(),ans1=0,ans2=0;
        int l=0,r=0,sum=0;
        while(r<n)
        {
            sum = sum+nums[r];
            while(sum>goal-1 && l<=r)
            {
                sum = sum-nums[l];
                l++;
            }
            ans1 = ans1+(r-l+1);
            r++;
        }
        l=0,r=0,sum=0,ans2=0;
        while(r<n)
        {
            sum = sum+nums[r];
            while(sum>goal)
            {
                sum = sum-nums[l];
                l++;
            }
            ans2 = ans2+(r-l+1);
            r++;
        }
        return ans2-ans1;
    }
};