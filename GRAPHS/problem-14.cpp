// find eventual safe states
// leetcode - 802
class Solution {
public:
    bool dfs(int cur,vector<vector<int>>& graph,vector<bool> &visited,vector<bool> &path,vector<bool> &check)
    {
        visited[cur] = true;
        path[cur] = true;
        for(int i=0;i<graph[cur].size();i++)
        {
            if(!visited[graph[cur][i]])
            {
                if(dfs(graph[cur][i],graph,visited,path,check))
                    return true;
            }
            else if(path[graph[cur][i]])
                return true;
        }
        path[cur] = false;
        check[cur] = true;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // optimal -> a variation of cycle detection technique tc-o(2V+E) sc-o(3V)
        int n = graph.size();
        vector<int> ans;
        vector<bool> visited(n,false);
        vector<bool> path(n,false);
        vector<bool> check(n,false);
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
                dfs(i,graph,visited,path,check);
        }
        for(int i=0;i<n;i++)
        {
            if(check[i])
                ans.push_back(i);
        }
        return ans;
    }
};