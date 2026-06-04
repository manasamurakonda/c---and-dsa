// GFG - detect cycle in directed graph
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // optimal -> topo sort tc-o(2V+E) sc-o(V)
        vector<vector<int>> adj(V);
        vector<bool> visited(V,false);
        vector<int> indegree(V,0);
        vector<int> ans;
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            indegree[edges[i][1]] = indegree[edges[i][1]]+1;
        }
        queue<int> q;
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0){
                q.push(i);
                visited[i] = true;
            }
        }
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            ans.push_back(cur);
            for(auto it : adj[cur])
            {
                indegree[it]--;
                if(!visited[it] && indegree[it]==0)
                {
                    visited[it] = true;
                    q.push(it);
                }    
            }
        }
        return ans;
    }
};