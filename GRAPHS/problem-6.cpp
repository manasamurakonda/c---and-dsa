// detect a cycle in undirected graph using dfs
// GFG - Undirected Graph Cycle
class Solution {
  public:
    bool dfs(int cur,int prev,vector<int> adj[],vector<bool> &visited)
    {
        for(int i=0;i<adj[cur].size();i++)
        {
            if(!visited[adj[cur][i]])
            {
                visited[adj[cur][i]] = true;
                if(dfs(adj[cur][i],cur,adj,visited))
                    return true;
                    
            }
            else{
                if(adj[cur][i]!=prev)
                    return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // optimal ->dfs tc-o(V+2E) sc-o(V)
        int m = edges.size();
        vector<int> adj[V];
        vector<bool> visited(V,false);
        for(int i=0;i<m;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=0;i<V;i++){
            if(!visited[i])
            {
                visited[i] = true;
                if(dfs(i,-1,adj,visited))
                    return true;
            }
        }
        return false;
    }
};