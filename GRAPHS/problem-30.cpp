// Path With Minimum Effort
// leetcode - 1631
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // optimal -> dijkstra tc-o(nlogm) sc-o(n*m*4*log(n*m))
        int n = heights.size(),m=heights[0].size();
        vector<vector<int>> ans(n,vector<int> (m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        ans[0][0] = 0;
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,1,0,-1};
        while(!pq.empty())
        {
            int maxi = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(ans[row][col]<maxi)
                continue;
            for(int i=0;i<4;i++)
            {
                int newrow = delrow[i]+row;
                int newcol = delcol[i]+col;
                if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && max(maxi,abs(heights[row][col]-heights[newrow][newcol]))<ans[newrow][newcol])
                {
                    pq.push({max(maxi,abs(heights[row][col]-heights[newrow][newcol])),{newrow,newcol}});
                    ans[newrow][newcol] = max(maxi,abs(heights[row][col]-heights[newrow][newcol]));
                }
            }
        }
        return ans[n-1][m-1];
    }
};