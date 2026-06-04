// permutations
// leetcode - 46
class Solution {
public:
    void compute(int n, vector<int> &nums,vector<vector<int>> &ans,vector<int> temp,vector<int> flag)
    {
        if(temp.size()==n)
        {
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<n;i++)
        {
            if(flag[i]==0)
            {
                temp.push_back(nums[i]);
                flag[i]=1;
                compute(n,nums,ans,temp,flag);
                flag[i] = 0;
                temp.pop_back();
            }
        }
    }
    void compute1(int ind,int n,vector<int> nums,vector<vector<int>> &ans,vector<int> temp)
    {
        if(temp.size()==n){
         ans.push_back(temp);
            return;
        }

        for(int i=ind;i<n;i++){
            swap(nums[i],nums[ind]);
            temp.push_back(nums[ind]);
            compute1(ind+1,n,nums,ans,temp);
            swap(nums[i],nums[ind]);
            temp.pop_back();
        }
    }
    or
    void compute1(int ind,int n,vector<int> nums,vector<vector<int>> &ans)
    {
        if(ind==n){
         ans.push_back(nums);
            return;
        }

        for(int i=ind;i<n;i++){
            swap(nums[i],nums[ind]);
            compute1(ind+1,n,nums,ans);
            swap(nums[i],nums[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        // brute -> for loop and flag array(recursion)
        // tc- o(n! * n) sc - o(2n)
        /*int n = nums.size();
        vector<vector<int>> ans;
        vector<int> flag(n,0);
        compute(n,nums,ans,{},flag);
        return ans;*/

        // optimal -> swapping , for loop, recursion
        // tc-o(n!) sc-o(n)
        int n = nums.size();
        vector<vector<int>> ans;
        compute1(0,n,nums,ans,{});
        return ans;
    }
};