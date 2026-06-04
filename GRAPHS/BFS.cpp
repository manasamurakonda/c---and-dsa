// GFG - BFS of graph
class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // tc-o(V+2E) sc- o(V)
        vector<int> ans;
        int n = adj.size();
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                queue<int> q;
                q.push(i);
                visited[i] = true;
                while(!q.empty())
                {
                    int temp = q.front();
                    q.pop();
                    ans.push_back(temp);
                    for(auto it : adj[temp])
                    {
                        if(!visited[it])
                        {
                            q.push(it);
                            visited[it] = true;
                        }
                    }
                }
            }
        }
        return ans;
    }
};