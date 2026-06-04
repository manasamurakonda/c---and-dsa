// GFG - Dijkstra
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // optimal -> dijkstra using priority queue tc-o(ElogV) sc-o(V^2)
        vector<vector<pair<int,int>>> adj(V);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,src});
        vector<int> ans(V,INT_MAX);
        ans[src] = 0;
        while(!pq.empty())
        {
            int cur = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            if(dist>ans[cur])
                continue;
            for(auto it : adj[cur])
            {
                if(ans[it.first]>dist+it.second)
                {
                    ans[it.first] = dist+it.second;
                    pq.push({dist+it.second,it.first});
                }
            }
        }
        return ans;
    }
};