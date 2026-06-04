// GFG - Shortest path in Directed Acyclic Graph
class Solution {
  public:
    void dfs(int cur,vector<vector<pair<int,int>>> &adj,vector<bool> &visited,stack<int> &st)
    {
        visited[cur] = true;
        for(auto it : adj[cur])
        {
            int node = it.first;
            if(!visited[node])
                dfs(node,adj,visited,st);
        }
        st.push(cur);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // optimal -> toposort(as graph is acyclic) + relaxation  tc-o(V+E)+o(V+E)+o(V) sc-o(E+V+V)
        vector<int> ans(V,INT_MAX);
        vector<vector<pair<int,int>>> adj(V);
        for(int i=0;i<E;i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        vector<bool> visited(V,false);
        stack<int> st;
        dfs(0,adj,visited,st);
        // relaxation
        ans[0] = 0;
        while(!st.empty())
        {
            int cur = st.top();
            st.pop();
            int dist = ans[cur];
            for(auto it : adj[cur])
            {
                int node = it.first;
                int wt = it.second;
                ans[node] = min(ans[node],dist+wt);
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
