// cheapest flights with k stops
// leetcode - 787
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // optimal -> bfs with relaxation
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<flights.size();i++)
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        vector<int> dist(n,INT_MAX);
        dist[src] = 0;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        while(!q.empty())
        {
            int stops = q.front().first;
            int city = q.front().second.first;
            int distance = q.front().second.second;
            q.pop();
            for(auto it : adj[city])
            {
                if(distance+it.second<dist[it.first] && stops<=k){
                    dist[it.first] = distance+it.second;
                    q.push({stops+1,{it.first,distance+it.second}});
                }
            }
        }
        if(dist[dst]==INT_MAX)
            return -1;
        return dist[dst];
    }
};