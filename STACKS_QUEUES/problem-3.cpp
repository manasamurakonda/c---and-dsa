// GFG - next greater element
// leetcode  - 496
class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // brute -> nested loops tc-o(n^2) sc-o(1)
        /*int n = arr.size();
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(arr[j]>arr[i])
                {
                    ans.push_back(arr[j]);
                    break;
                }
            }
            if(ans.size()<i+1)
                ans.push_back(-1);
        }
        if(ans.size()<arr.size())
            ans.push_back(-1);
        return ans;*/
        
        // optimal -> monotonic stack tc-o(3n) sc-o(n)
        int n = arr.size();
        stack<int> st;
        vector<int> ans;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<=arr[i])
                st.pop();
            if(st.empty())
                ans.push_back(-1);
            else ans.push_back(st.top());
            st.push(arr[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};