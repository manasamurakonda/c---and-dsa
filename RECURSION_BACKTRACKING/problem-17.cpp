// subsets sum -2
// leetcode - 90

class Solution {
public:
    void compute(int ind,int n,vector<int> &nums,vector<vector<int>> &ans,vector<int> temp)
    {
        ans.push_back(temp);
        for(int i=ind;i<n;i++)
        {
            if(i-1<ind || nums[i]!=nums[i-1])
            {
                temp.push_back(nums[i]);
                compute(i+1,n,nums,ans,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // brute -> use pick and not pick using set

        // optimal -> for loop pick tc-o(2^n) sc-o(2^n)
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        compute(0,n,nums,ans,{});
        return ans;
    }
};