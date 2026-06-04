// search in rotated sorted array
// leetcode -> 33
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // brute -> linear search
        /*int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==target)
                return i;
        }
        return -1;*/
        // optimal - > binary search
        int n=nums.size(),low=0,high = n-1;
        while(low<=high)
        {
            int mid = (low+high)/2;

            if(nums[mid]==target)
                return mid;
            else if(nums[low]<=nums[mid])
            {
                if(target >=nums[low] && target<nums[mid])
                    high = mid-1;
                else low =mid+1;
            }
            else
            {
                if(target>nums[mid] && target<=nums[high])
                    low = mid+1;
                else high = mid-1;
            }
        }
        return -1;
    }
};