// GFG - Shortest Path in Undirected Graph
class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // optimal -> bfs(as graph is unit distance overall) tc-o(V+2E) sc-o(V)
        vector<int> ans(V,INT_MAX);
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(V,false);
        queue<int> q;
        q.push(src);
        ans[src] = 0;
        visited[src] = true;
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            for(auto it : adj[cur])
            {
                if(!visited[it]){
                    ans[it] = min(ans[it],ans[cur]+1);
                    q.push(it);
                    visited[it] = true;
                }
            }
        }
        for(int i=0;i<V;i++)
        {
            if(ans[i] == INT_MAX)
                ans[i] = -1;
        }
        return ans;
    }
};