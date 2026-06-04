// ceil in sorted array gfg
class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        // brute -> linear search
        
        // optimal -> implementing lower bound
        int n = arr.size();
        int low=0,high = n-1,ans= -1;
        while(low<=high)
        {
            int mid= (low+high)/2;
            if(arr[mid]>=x)
            {
                ans = mid;
                high =mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};