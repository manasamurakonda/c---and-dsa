// GFG - Print Longest Increasing Subsequence
class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        // tabulation sepcial algorithm to print LIS
        int n = arr.size();
        vector<int> dp(n,1),hash(n);
        for(int i=0;i<n;i++)
        {
            hash[i] = i;
        }
        int maxi = 0;
        for(int ind=0;ind<n;ind++)
        {
            for(int prev=0;prev<ind;prev++)
            {
                if(arr[prev]<arr[ind])
                {
                    if(dp[ind]<1+dp[prev]){
                        dp[ind] = 1+dp[prev];
                        hash[ind] = prev;
                    }
                    if(dp[maxi]<dp[ind])
                        maxi = ind;
                }
            }
        }
        int x = dp[maxi];
        vector<int> ans(x);
        x--;
        while(hash[maxi]!=maxi)
        {
            ans[x--] = arr[maxi];
            maxi = hash[maxi];
        }
        ans[x] = arr[maxi];
        return ans;
    }
};