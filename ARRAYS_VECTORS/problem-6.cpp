// two sum leetcode-1
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // brute -> nested loops eh
       /*  int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans; */

        // optimal - > map vadochemo chudu
        /* int n=nums.size();
        vector<int> ans;
        map<int,int> m;
        for(int i=0;i<n;i++)
        {
            if(m.find(target-nums[i])!=m.end())
            {
                ans.push_back(m[target-nums[i]]);
                ans.push_back(i);
                break;
            }
            else{
                m[nums[i]]=i;
            }
        }
        return ans; */
    }
};