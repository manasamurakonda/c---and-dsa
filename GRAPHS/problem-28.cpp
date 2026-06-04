// GFG - Shortest Path in an Undirected Graph
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // optimal -> dijkstra tc-o(mlogn) sc-o(n)
        vector<int> ans;
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]}); 
        }
        vector<int> parent(n+1,-1);
        vector<int> weight(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,1});
        weight[1] = 0;
        while(!pq.empty())
        {
            int dist = pq.top().first;
            int cur = pq.top().second;
            pq.pop();
            if(dist>weight[cur])
                continue;
            for(auto it : adj[cur])
            {
                if(dist+it.second<weight[it.first])
                {
                    weight[it.first] = dist+it.second;
                    pq.push({weight[it.first],it.first});
                    parent[it.first] = cur;
                }
            }
        }
        if(weight[n]==INT_MAX)
            return {-1};
        int ind = n;
        while(ind!=-1)
        {
            ans.push_back(ind);
            ind = parent[ind];
        }
        ans.push_back(weight[n]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};