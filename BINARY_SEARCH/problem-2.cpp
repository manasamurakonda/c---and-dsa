// lower bound
// not present on leetcode
class Solution{
public:
    int lowerBound(vector<int> &nums, int x){
        // brute -> linear search
        
        // optimal -> using binary serach
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
};