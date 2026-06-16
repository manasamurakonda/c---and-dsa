// find first and last position of element in sorted array
// leetcode - 34
class Solution {

public:
    int lb(vector<int> & nums,int target)
    {
        int n=nums.size(),low = 0,high =n-1,ans = -1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(nums[mid]>=target)
            {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
    int ub(vector<int> & nums,int target)
    {
        int n=nums.size(),low = 0,high =n-1,ans = -1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(nums[mid]>target)
            {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        // linear search
        /*int n=nums.size(),left = -1,right = -1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==target)
            {
                if(left == -1)
                    left = i;
                right = i;
            }
        }
        return {left,right};*/

        //optimal-1 binary search using upper bound and lower bound
        int n=nums.size();
        int left = lb(nums,target);
        if(left==-1 || nums[left]!=target)
            return {-1,-1};
        int right = ub(nums,target);
        if(right==-1)
            return {left,n-1};
        return {left,right-1};

        //optimal-2 simple binary search
        /*int n = nums.size(),low = 0,high = n-1,left = -1,right = -1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(nums[mid]>=target)
            {
                left = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        if(left == -1 || nums[left]!=target)
            return {-1,-1};
        low = 0,high = n-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(nums[mid]<=target)
            {
                right = mid;
                low = mid+1;
            }
            else high=mid-1;
        }
        return {left,right};*/
    }
};