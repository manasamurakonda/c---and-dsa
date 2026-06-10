// LIS using binary search
// leetcode - 300
class Solution {
public:
    int lowerBound(vector<int> &nums, int x){
        int n = nums.size();
        int ans=-1,low=0,high=n-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(nums[mid]>=x)
            {
                ans = mid;
                high= mid-1;
            }
            else low= mid+1;
        }
        return ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        // using binary search
        int n = nums.size();
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            if(nums[i]>ans.back())
                ans.push_back(nums[i]);
            else{
                ans[lowerBound(ans,nums[i])] = nums[i];
            }
        } 
        return ans.size();
    }
};