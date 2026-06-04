// maximum consecutive ones 3
// leetcode-1004
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // brute -> generating all subarrays
        /*int n=nums.size(),ans =0,count=0;
        for(int i=0;i<n;i++)
        {
            count=0;
            for(int j=i;j<n;j++)
            {
                if(nums[j]==0)
                    count++;
                if(count > k)
                    break;
                ans = max(ans,j-i+1);
            }
        }
        return ans;*/
        // better (sliding window pattern 2) o(2n)
        /*int n=nums.size();
        int ans=0,count=0;
        int l=0,r=0;
        while(r<n)
        {
            if(nums[r]==0)
            {
                count++;
            }
            if(count>k){
                while(nums[l]==1)
                {
                    l++;
                }
                l++;
                count--;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;*/
        // optimal (sliding window pattern 2 optimization)
        int n=nums.size(),ans=0,count=0;
        int l=0,r=0;
        while(r<n)
        {
            if(nums[r]==0)
                count++;
            if(count>k)
            {
                if(nums[l]==0)
                    count--;
                l++;
            }
            if(count<=k)
            {
                ans = max(ans,r-l+1);
            }
            r++;
        }
        return ans;
    }
};