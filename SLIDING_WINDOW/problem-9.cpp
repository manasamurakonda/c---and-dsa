// count number of nice subarrays
// leetcode - 1248
class Solution {
public:
    int slidingWindowPattern2(vector<int>& nums,int k)
    {
        int n = nums.size(),ans=0,l=0,r=0,count=0;
        while(r<n)
        {
            if(nums[r]%2!=0)
            {
                count++;
            }
            while(count>k)
            {
                if(nums[l]%2!=0)
                    count--;
                l++;
            }
            ans = ans+(r-l+1);
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        // brute -> generating all subarrays
        /*int n = nums.size(),ans=0;
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=i;j<n;j++)
            {
                if(nums[j]%2!=0)
                    count++;
                if(count>k)
                    break;
                if(count == k)
                    ans++;
            }
        }
        return ans;*/


        // optimal -> sliding window(pattern 3)
        return slidingWindowPattern2(nums,k)-slidingWindowPattern2(nums,k-1);
    }
};