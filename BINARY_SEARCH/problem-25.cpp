// painters partition problem 2 - GFG
class Solution {
  public:
    int check(int painters, vector<int>& nums, int minTime)
    {
        int n = nums.size(),ans= 0,time = 0;
        for(int i=0;i<n;i++)
        {
            time  = time+nums[i];
            if(time>minTime)
            {
                ans++;
                time = nums[i];
            }
        }
        ans++;
        if(ans<=painters)
            return 1;
        return 0;
    }
    int minTime(vector<int>& arr, int k) {
        // brute - > linear iteration
        /*int mini = ( *max_element(arr.begin(),arr.end()));
        int maxi = ( accumulate(arr.begin(),arr.end(),0));
        for(int i=mini;i<=maxi;i++)
        {
            if(check(k,arr,i)==1)
                return i;
        }
        return -1;*/

        // optimal -> binary search on answers2 max(min)
        int low = ( *max_element(arr.begin(),arr.end()));
        int high = ( accumulate(arr.begin(),arr.end(),0));
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(check(k,arr,mid)==1)
                high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};