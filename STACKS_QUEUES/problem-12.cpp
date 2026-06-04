// remove k-digits
// leetcode - 402

class Solution {
public:
    string removeKdigits(string num, int k) {
        // optimal -> monotonic stack tc-o(5n) sc-o(n)
        int n = num.size(),cnt=0;
        stack<char> st; 
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && st.top()>num[i] && cnt<k)
            {
                cnt++;
                st.pop();
            }
            st.push(num[i]);
        }
        string ans="";
        while(!st.empty() && cnt<k)
        {
            st.pop();
            cnt++;
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        while(ans.size()!=0 && ans.back()=='0')
            ans.pop_back();
        reverse(ans.begin(),ans.end());
        if(ans.size()==0)
            return "0";
        return ans;
    }
};