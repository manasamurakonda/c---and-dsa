// GFG - next smaller element

class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        // brute -> nested loops tc-o(n^2) sc-o(1)
        /*int n = arr.size();
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(arr[i]>arr[j])
                {
                    ans[i] = arr[j];
                    break;
                }
            }
        }
        return ans;*/
        // optimal -> monotonic stack tc-o(2n) sc-o(n)
        int n = arr.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()>=arr[i])
                st.pop();
            if(!st.empty())
                ans[i] = st.top();
            st.push(arr[i]);
        }
        return ans;
    }
};