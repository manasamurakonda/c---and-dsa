// permutations 2
// leetcode - 47
class Solution {
public:
    void compute(int n,vector<int> &nums,vector<vector<int>> &ans,vector<int> temp,vector<int> flag)
    {
        if(temp.size()==n)
        {
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<n;i++)
        {
            if(i-1<0 || nums[i-1]!=nums[i] || flag[i-1]==0)
            {
                if(flag[i]==0)
                {
                    temp.push_back(nums[i]);
                    flag[i] = 1;
                    compute(n,nums,ans,temp,flag);
                    flag[i] = 0;
                    temp.pop_back();
                }
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // recursion -> (for loop) tc-o(n!*n) sc-o(2n)
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> flag(n,0);
        compute(n,nums,ans,{},flag);
        return ans;
    }
};