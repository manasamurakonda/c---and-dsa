// find eventual safe states
// leetcode - 802
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // optimal -> reverse edges and kahns algo tc-o(n+E)+o(n)+o(n+E)+o(nlogn) sc-o(n+E)+o(n) 
        vector<int> ans;
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto it : graph[i])
            {
                adj[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0){
                q.push(i);
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
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};