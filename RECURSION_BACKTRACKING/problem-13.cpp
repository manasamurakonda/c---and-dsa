// GFG - Check if there exists a subsequence with sum K
// recursion - take and not take
// tc-o(2^n) sc - o(n)
class Solution {
  public:
    bool compute(int ind,int n,vector<int> &arr,int k,int sum,vector<int> &ans)
    {
        if(ind>=n)
        {
            if(sum == k)
            {
                return true;
            }
            return false;
        }
        
        sum = sum + arr[ind];
        ans.push_back(arr[ind]);
        
        if(compute(ind+1,n,arr,k,sum,ans))
            return true;
        sum = sum - arr[ind];
        ans.pop_back();
        
        if(compute(ind+1,n,arr,k,sum,ans))
            return true;
        return false;
    }
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        vector<int> ans;
        return compute(0, n, arr,k,0,ans);
    }
};