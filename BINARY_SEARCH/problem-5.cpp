// floor in sorted array gfg
class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        // brute -> linear search

        // optimal -> binary search
        int n = arr.size();
        int low = 0,high = n-1,flr = -1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(arr[mid]<=x){
                flr = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        return flr;
    }
};