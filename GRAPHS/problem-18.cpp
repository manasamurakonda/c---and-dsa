// course schedule - 1
// leetcode - 207
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // optimal -> topo sort tc-o(2V+E) sc-o(V)
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        vector<int> ans;
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
                q.push(i);
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
                    q.push(it);
            }
        }
        if(ans.size()==numCourses)
            return true;
        return false;
    }
};