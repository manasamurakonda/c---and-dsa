// prims algorithm
// GFG - Minimum Spanning Tree
class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // optimal -> prims algorithm tc-o(ElogE) sc-o(E)
        vector<vector<pair<int,int>>> adj(V);
        int n = edges.size();
        for(int i=0;i<n;i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        vector<pair<int,int>> mst;
        int sum = 0;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,-1}});
        vector<bool> visited(V,false);
        while(!pq.empty())
        {
            int dist = pq.top().first;
            int cur = pq.top().second.first;
            int parent = pq.top().second.second;
            pq.pop();
            if(visited[cur])
                continue;
            visited[cur] = true;
            if(parent!=-1)
            {
                mst.push_back({parent,cur});
                sum = sum + dist;
            }
            for(auto it : adj[cur])
            {
                if(!visited[it.first])
                {
                    pq.push({it.second,{it.first,cur}});
                }
            }
        }
        return sum;
    }
};