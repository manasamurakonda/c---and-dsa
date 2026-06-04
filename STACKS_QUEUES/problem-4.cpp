// next greater element 2
// leetcode - 503
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // brute -> nested loops tc-o(n^2) sc-o(1)
        /*int n = nums.size();
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n+i;j++)
            {
                if(nums[j%n]>nums[i])
                {
                    ans[i] = nums[j%n];
                    break;
                }
            }
        }
        return ans;*/

        // optimal -> monotonic stack tc-o(4n) sc-o(n)
        int n = nums.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<=nums[i])
                st.pop();
            st.push(nums[i]);
        }
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<=nums[i])
                st.pop();
            if(!st.empty())
                ans[i]=st.top();
            st.push(nums[i]);
        }
        return ans;
    }
};