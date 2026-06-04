// majority element 2
// leetcode-229
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // brute -> nested loops and (how many numbers do you think could be the answer?)
        /*int n = nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(ans.size()==0 || ans[0]!=nums[i])
            {
                int count = 0;
                for(int j=i;j<n;j++)
                {
                    if(nums[j]==nums[i])
                        count++;
                    if(count>(n/3)){
                        ans.push_back(nums[i]);
                        break;
                    }
                }
            }
            if(ans.size()==2)
                break;
        }
        return ans;*/

        // better - > hashing
        /*int n = nums.size();
        vector<int> ans;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
        {
            if(ans.size()==0 || ans[0]!=nums[i])
            {
                m[nums[i]]++;
                if(m[nums[i]]>(n/3))
                    ans.push_back(nums[i]);
            }
            if(ans.size()==2)
                break;
        }
        return ans;*/

        // optimal -> moore's voting algo
        int n = nums.size();
        vector<int> ans;
        int c1=0,e1=INT_MIN,c2=0,e2=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(c1==0 && nums[i]!=e2)
            {
                c1=1;
                e1=nums[i];
            }
            else if(c2==0 && nums[i]!=e1)
            {
                c2=1;
                e2=nums[i];
            }
            else if(nums[i]==e1)
                c1++;
            else if(nums[i]==e2)
                c2++;
            else{ 
                c1--;
                c2--;
            }
        }
        c1=0;
        c2=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==e1)
                c1++;
            else if(nums[i]==e2)
                c2++;
        }
        if(c1>(n/3))
            ans.push_back(e1);
        if(c2>(n/3))
            ans.push_back(e2);
        return ans;
    }
};