// GFG - DFS of Graph
class Solution {
  public:
    void traversal(int cur,vector<vector<int>>& adj,vector<int> &ans,vector<bool> &visited)
    {
        ans.push_back(cur);
        for(auto it : adj[cur])
        {
            if(!visited[it])
            {
                visited[it] = true;
                traversal(it,adj,ans,visited);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // tc-o(V+2E) sc-o(V)
        int n = adj.size();
        vector<bool> visited(n,false);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                visited[i] = true;
                traversal(i,adj,ans,visited);
            }
        }
        return ans;
    }
};