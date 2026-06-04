// find minimum in rotated sorted array
// leetcode - 153
class Solution {
public:
    int findMin(vector<int>& nums) {
        // brute -> finding smallest element in an array
        /*int n = nums.size(),ans=nums[0];
        for(int i=0;i<n;i++)
        {
            ans = min(ans,nums[i]);
        }
        return ans;*/
        // optimal -> binary search
        int n = nums.size(),ans = nums[0];
        int low = 0,high =n-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(nums[low]<=nums[mid])
            {
                ans = min(ans,nums[low]);
                low = mid+1;
            }
            else{
                ans = min(ans,nums[mid]);
                high = mid-1;
            }
        }
        return ans;
    }
};