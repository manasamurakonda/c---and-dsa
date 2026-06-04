// GFG - Connected Components in an Undirected Graph
class Solution {
  public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> adj[V];
        for(int i=0;i<n;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<vector<int>> ans;
        vector<bool> flag(V,false);
        for(int i=0;i<V;i++)
        {
            if(!flag[i])
            {
                queue<int> q;
                vector<int> conn;
                q.push(i);
                flag[i] = true;
                while(!q.empty())
                {
                    int temp = q.front();
                    q.pop();
                    conn.push_back(temp);
                    
                    for(int j : adj[temp])
                    {
                        if(!flag[j]){
                            q.push(j);
                            flag[j] = true;
                        }
                    }
                }
                ans.push_back(conn);
            }
        }
        return ans;
    }
};
