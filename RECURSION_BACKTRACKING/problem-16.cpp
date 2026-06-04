// GFG - subsets sum
// subset sum - 1
// optimal -> pick and not pick (recursion) tc- o(2^n) sc - o(2^n)
class Solution {
  public:
    void compute(int ind,int n,vector<int> &arr,vector<int> &ans,int sum)
    {
        if(ind>=n)
        {
            ans.push_back(sum);
            return;
        }
        
        sum = sum + arr[ind];
        compute(ind+1,n,arr,ans,sum);
        sum = sum - arr[ind];
        compute(ind+1,n,arr,ans,sum);
    }
    vector<int> subsetSums(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        compute(0,n,arr,ans,0);
        return ans;
    }
};