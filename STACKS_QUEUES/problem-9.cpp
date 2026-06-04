// asteroid collision
// leetcode-735

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // optimal -> monotonic stack tc-o(2n) sc-o(n)
        int n = asteroids.size();
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            if(asteroids[i]<0)
                st.push(asteroids[i]);
            else{
                if(st.empty() || st.top()>0)
                    st.push(asteroids[i]);
                else if(asteroids[i]>=abs(st.top()))
                {
                    while(!st.empty() && asteroids[i]>abs(st.top()) && st.top()<0)
                        st.pop();
                    if(st.empty() || st.top()>0)
                        st.push(asteroids[i]);
                    else if(asteroids[i] == abs(st.top()))
                        st.pop();
                }
            }
        }
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};