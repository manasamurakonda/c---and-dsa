// combination sum
// leetcode - 39
// recursion - pick and not pick where we can do infinite picks of a single element
// tc- o(2^target * k) sc - o(k*x)
class Solution {
public:
    void compute(int ind,int n,vector<int>& candidates,int target,vector<int> temp,vector<vector<int>> &ans,int sum)
    {
        if(sum>=target || ind>=n)
        {
            if(sum == target)
                ans.push_back(temp);
            return;
        }

        sum = sum + candidates[ind];
        temp.push_back(candidates[ind]);
        compute(ind,n,candidates,target,temp,ans,sum);
        sum = sum - candidates[ind];
        temp.pop_back();
        compute(ind+1,n,candidates,target,temp,ans,sum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        compute(0,n,candidates,target,{},ans,0);
        return ans;
    }
};