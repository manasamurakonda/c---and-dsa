// search in rotated sorted array 2
// leetcode - 81
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // brute -> linear search
        /*int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==target)
                return true;
        }
        return false;*/

        // optimal -> binary search (think of the case where nums[low]==nums[mid]==nums[high] and try to solve it)
        int n = nums.size(),low=0,high = n-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(nums[mid]==target)
                return true;
            else if(nums[low]==nums[mid] && nums[high]==nums[mid])
            {
                low++;
                high--;
            }
            else if(nums[low]<=nums[mid])
            {
                if(target>=nums[low] && target<nums[mid])
                    high = mid-1;
                else low = mid+1;
            }
            else{
                if(target>nums[mid] && target<=nums[high])
                    low = mid+1;
                else high = mid-1;
            }
        }
        return false;
    }
};