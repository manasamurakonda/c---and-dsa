// detect cycle in directed graph
// leetcode - 210
class Solution {
public:
    bool dfs(int i,vector<vector<int>> &adj,vector<int> &ans,vector<bool> &visited,vector<bool> &path)
    {
        visited[i] = true;
        path[i] = true;
        for(int j=0;j<adj[i].size();j++)
        {
            if(!visited[adj[i][j]])
            {
                if(dfs(adj[i][j],adj,ans,visited,path))
                    return true;
            }
            else if(path[adj[i][j]]==true)
                return true;
        }
        path[i] = false;
        ans.push_back(i);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // optimal -> use path visit concept to detect cycle...(a bit of topo sort concept included) tc-o(V+E) sc-o(V)
        vector<int> ans;
        vector<vector<int>> adj(numCourses);
        int n = prerequisites.size();
        for(int i=0;i<n;i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<bool> visited(numCourses,false);
        vector<bool> path(numCourses,false);
        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i]){
                if(dfs(i,adj,ans,visited,path))
                    return {};
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};