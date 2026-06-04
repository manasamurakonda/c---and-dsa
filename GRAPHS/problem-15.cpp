// GFG - Topological Sort
class Solution {
  public:
    void dfs(int cur,vector<vector<int>> &adj,vector<bool> &visited,vector<int> &ans)
    {
        visited[cur] = true;
        for(int i=0;i<adj[cur].size();i++)
        {
            if(!visited[adj[cur][i]])
                dfs(adj[cur][i],adj,visited,ans);
        }
        ans.push_back(cur);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // optimal -> just try to store the nodes first which depend on others and reverse the answer or use a stack tc-o(V+E) sc-o(2V)
        vector<int> ans;
        vector<vector<int>> adj(V);
        vector<bool> visited(V,false);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
                dfs(i,adj,visited,ans);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};