// combination sum -2
// leetcode - 40
class Solution {
public:
    void compute(int ind,int n,vector<int>& candidates,int target,set<vector<int>> &s,vector<int> temp,int sum)
    {
        if(sum>= target || ind>=n)
        {
            if(sum == target)
                s.insert(temp);
            return;
        }

        sum = sum + candidates[ind];
        temp.push_back(candidates[ind]);
        compute(ind+1,n,candidates,target,s,temp,sum);
        sum = sum - candidates[ind];
        temp.pop_back();
        compute(ind+1,n,candidates,target,s,temp,sum);
    }
    void compute1(int ind,int n,vector<int>& candidates,int target,vector<vector<int>> &ans,vector<int> temp,int sum)
    {
        if(sum>= target || ind>=n)
        {
            if(sum == target)
                ans.push_back(temp);
            return;
        }

        for(int i=ind;i<n;i++)
        {
            if(i-1< ind || candidates[i]!=candidates[i-1])
            {
                sum = sum + candidates[i];
                temp.push_back(candidates[i]);
                compute1(i+1,n,candidates,target,ans,temp,sum);
                sum = sum - candidates[i];
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // brute -> pick and not pick 
        /*sort(candidates.begin(),candidates.end());
        int n = candidates.size();
        vector<vector<int>> ans;
        set<vector<int>> s;
        compute(0,n,candidates,target,s,{},0);
        for(auto it : s)
            ans.push_back(it);
        return ans;*/

        //optimal -> with which element you start with and skip duplicates
        int n = candidates.size();
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        compute1(0,n,candidates,target,ans,{},0);
        return ans;
    }
};