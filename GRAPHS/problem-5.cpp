// detect a cycle in undirected graph using bfs
// GFG - Undirected Graph Cycle
class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // optimal ->bfs tc-o(V+2E) sc-o(V)
        int m = edges.size();
        vector<int> adj[V];
        vector<bool> visited(V,false);
        for(int i=0;i<m;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        queue<pair<int,int>> q;
        for(int i=0;i<V;i++){
            if(!visited[i])
            {
                visited[i] = true;
                q.push({i,-1});
                while(!q.empty())
                {
                    int temp = q.front().first;
                    int prev = q.front().second;
                    q.pop();
                    for(int i=0;i<adj[temp].size();i++)
                    {
                        if(!visited[adj[temp][i]])
                        {
                            visited[adj[temp][i]] = true;
                            q.push({adj[temp][i],temp});
                        }
                        else{
                            if(adj[temp][i]!=prev)
                                return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};