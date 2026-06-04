// generate all subsequences or subsets
// leetcode - 78
class Solution {
public:
    void subsequence(int ind,int n, vector<vector<int>> &ans,vector<int> &nums,vector<int> &temp)
    {
        if(ind >=n)
        {
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[ind]);
        subsequence(ind+1,n,ans,nums,temp);
        temp.pop_back();
        subsequence(ind+1,n,ans,nums,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        // recursion - pick and not pick
        // tc-o(2^n)
        // sc-o(n)
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        subsequence(0,n,ans,nums,temp);
        return ans;
    }
};