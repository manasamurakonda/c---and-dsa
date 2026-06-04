// valid parentheses
// leetcode - 20

class Solution {
public:
    bool isValid(string s) {
        // optimal -> using stack tc-o(n) sc-o(n)
        int n = s.size();
        stack<char> st;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='{' || s[i]=='(' || s[i]=='[')
                st.push(s[i]);
            else
            {
                if(st.empty())
                    return false;

                char x = st.top();
                if((s[i]==')' && x!='(') || (s[i]=='}' && x!='{') || (s[i]==']' && x!='['))
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
};