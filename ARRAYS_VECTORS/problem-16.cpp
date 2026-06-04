// rearrange array elements by sign
// leetcode - 2149
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // brute -> storing positives and negatives
        /*vector<int> ans;
        vector<int> pos;
        vector<int> neg;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
                pos.push_back(nums[i]);
            else
                neg.push_back(nums[i]);
        }
        int x=0;
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
                ans.push_back(pos[i/2]);
            else
                ans.push_back(neg[x++]);
        }
        return ans;*/

        // optimal - > cant solve this problem with o(1) space complexity but can solve it in o(n) time complexity
        int n = nums.size();
        int pos = 0,neg=1;
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0){
                ans[pos] = nums[i];
                pos = pos + 2;
            }
            else{
                ans[neg] = nums[i];
                neg = neg + 2;
            }
        }
        return ans;
    }
};