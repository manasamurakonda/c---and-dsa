// longest subarray with sum k leetcode-325(locked)
// gfg longest subarray with sum k


class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        
        // brute - > generating all subarrays
        /*int ans = 0;
        int n = arr.size(),sum = 0;
        for(int i=0;i<n;i++)
        {
            sum = 0;
            for(int j=i;j<n;j++)
            {
                sum = sum + arr[j];
                if(sum == k)
                {
                    ans = max(ans,j-i+1); 
                }
            }
        }
        return ans; */
        
        // better - > hashing (prefix sum)
        int n = arr.size(),sum = 0,ans = 0;
        map<int,int> m;
        m[0] = -1;
        for(int i=0;i<n;i++)
        {
            sum = sum + arr[i];
            if(m.find(sum-k)!=m.end())
            {
                ans = max(ans,i-m[sum-k]);
            }
            if(m.find(sum)==m.end())
                m[sum] = i;
        }
        return ans;
        
        // optimal -> sliding window but only works for +ve array
    }
};