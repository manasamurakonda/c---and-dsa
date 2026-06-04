// maximum rectangle
// leetcode - 85

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // optimal -> largest rectangle in histogram approach tc-o(n*m)+o(n*2m) sc-o(m)+o(n*m)
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> prefix(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int x = 0;
                if(i-1>=0)
                {
                    x = x+prefix[i-1][j];
                }
                if(matrix[i][j]=='1')
                    prefix[i][j]=x+1;
                else
                    prefix[i][j]=0;
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            stack<pair<int,int>> st;
            for(int j=0;j<m;j++)
            {
                while(!st.empty() && prefix[i][j]<=st.top().first)
                {
                    int ele = st.top().first;
                    st.pop();
                    int prev = (!st.empty())? st.top().second: -1;
                    ans = max(ans,(j-prev-1)*ele);
                }
                st.push({prefix[i][j],j});
            }
            while(!st.empty())
            {
                int ele = st.top().first;
                st.pop();
                int prev = (!st.empty())? st.top().second: -1;
                ans = max(ans,(m-prev-1)*ele);
            }
        }
        return ans;
    }
};