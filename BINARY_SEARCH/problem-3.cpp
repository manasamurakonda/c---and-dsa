// upper bound
// not present on leetcode
class Solution{
public:
    int upperBound(vector<int> &nums, int x){
        // brute -> linear search
        
        // optimal -> using binary search
        int n = nums.size(),ans=-1;
        int low =0,high = n-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(nums[mid]>x)
            {
                ans=mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};