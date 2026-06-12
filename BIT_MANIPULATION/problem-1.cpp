// power set
// leetcode - 78
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // power set problem
        int n = nums.size();
        int tot = (1<<n);
        vector<vector<int>> ans;
        for(int i=0;i<tot;i++)
        {
            vector<int> temp;
            for(int j=0;j<n;j++)
            {
                if((i>>j)&1 == 1)
                    temp.push_back(nums[j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};