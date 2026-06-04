// sum of subarray minimums
// leetcode - 907

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        // brute -> nested loops tc-o(n^2) sc-o(1)
        /*long long n = arr.size();
        long long ans = 0;
        for(int i=0;i<n;i++)
        {
            int mini = INT_MAX;
            for(int j=i;j<n;j++)
            {
                mini = min(mini,arr[j]);
                ans = ans + mini;
            }
        }
        return ans%1000000007;*/

        // optimal -> monotonic stack tc-o(5n) sc-o(3n)
        int n = arr.size();
        long long ans = 0;
        vector<int> nse(n,n);
        vector<int> pse(n,-1);
        stack<pair<int,int>> st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top().first>=arr[i])
                st.pop();
            if(!st.empty())
                nse[i] = st.top().second;
            st.push({arr[i],i});
        }
        while(!st.empty())
            st.pop();
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && st.top().first>arr[i])
                st.pop();
            if(!st.empty())
                pse[i] = st.top().second;
            st.push({arr[i],i});
        }
        for(int i=0;i<n;i++)
            ans = ans+((long long)arr[i]*(long long)(i-pse[i])*(long long)(nse[i]-i));
        return ans%1000000007;
    }
};