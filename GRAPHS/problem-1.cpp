// number of provinces
// leetcode - 547
class Solution {
public:
    void dfs(int cur,vector<int> adj[],vector<bool> &visited)
    {
        for(auto it : adj[cur])
        {
            if(!visited[it])
            {
                visited[it] = true;
                dfs(it,adj,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        // optimal -> dfs or bfs tc-o(N+V+2E) sc-O(3V)
        int n = isConnected.size(),ans=0;
        vector<int> adj[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                ans++;
                visited[i] = true;
                dfs(i,adj,visited);
            }
        }
        return ans;
    }
};