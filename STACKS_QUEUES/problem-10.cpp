// largest rectangle in histogram
// leetcode - 84

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // brute -> nested loops tc-o(n^2) sc-o(1)
        /*int n = heights.size(),ans=0;
        for(int i=0;i<n;i++)
        {
            int count = 0;
            for(int j=i;j<n;j++)
            {
                if(heights[j]>=heights[i])
                    count++;
                else break;
            }
            for(int j=i-1;j>=0;j--)
            {
                if(heights[j]>=heights[i])
                    count++;
                else break;
            }
            ans = max(ans,heights[i]*count);
        }
        return ans;*/

        // better -> monotonic stacks(nse and pse) tc-o(5n) sc-o(4n)
        /*int n =  heights.size();
        stack<pair<int,int>> st1,st2;
        vector<int> nse(n,n);
        vector<int> pse(n,-1);
        for(int i=0;i<n;i++)
        {
            while(!st1.empty() && st1.top().first>=heights[i])
                st1.pop();
            if(!st1.empty())
                pse[i]=st1.top().second;
            st1.push({heights[i],i});
        }
        for(int i=n-1;i>=0;i--)
        {
            while(!st2.empty() && st2.top().first>=heights[i])
                st2.pop();
            if(!st2.empty())
                nse[i]=st2.top().second;
            st2.push({heights[i],i});
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            int count = nse[i]-pse[i]-1;
            ans = max(ans,heights[i]*count);
        }
        return ans;*/

        // optimal -> monotonic stack (we can find nse and pse at the same time using one stack) tc-o(2n) sc-o(n) 
        int n = heights.size();
        stack<pair<int,int>> st;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && st.top().first>=heights[i])
            {
                int ele = st.top().first;
                st.pop();
                int prev = st.empty()? -1 : st.top().second;
                ans = max(ans,(i-prev-1)*ele);
            }
            st.push({heights[i],i});
        }
        while(!st.empty())
        {
            int ele = st.top().first;
            st.pop();
            int prev =  st.empty()? -1 : st.top().second;
            ans = max(ans,(n-prev-1)*ele);
        }
        return ans;
    }
};