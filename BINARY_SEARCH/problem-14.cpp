// find peak element
// leetcode - 162
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // brute -> linear iteration(just returning maximum element in array)
        /*int n = nums.size();
        int ans = -1;
        for(int i=0;i<n;i++)
        {
            if(ans == -1 || nums[i]>nums[ans])
            {
                ans = i;
            }
        }
        return ans;*/
        // brute -> linear iteration based on peak element condition
        /*int n = nums.size();
        if(n==1 || nums[0]>nums[1])
            return 0;
        if(nums[n-1]>nums[n-2])
            return n-1;
        for(int i=1;i<n-1;i++)
        {
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1])
               *1-- return i;
        }
        return -1;*/

        // binary search(focus on either the mid element is on raising slope or downing slope based on neighbours)
        int n = nums.size(),low = 1,high =n-2;
        if(n==1 || nums[0]>nums[1])
            return 0;
        if(nums[n-1]>nums[n-2])
            return n-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
                return mid;
            else if(nums[mid]<nums[mid-1])
                high = mid-1;
            else low = mid+1;
        }
        return -1;       
    }
};