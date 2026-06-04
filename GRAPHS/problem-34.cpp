// GFG - Bellman-Ford
class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // optimal -> bellmanford tc-o(V*edges.size()) sc-o(1)
        vector<int> dist(V,100000000);
        int n = edges.size();
        dist[src] = 0;
        for(int i=0;i<V-1;i++)
        {
            for(int j=0;j<n;j++)
            {
                int u = edges[j][0];
                int v = edges[j][1];
                int w = edges[j][2];
                if(dist[u]!=100000000 && dist[u]+w<dist[v])
                    dist[v] = dist[u]+w;
            }
        }
        for(int i=0;i<n;i++)
        {
            int u = edges[i][0];
                int v = edges[i][1];
                int w = edges[i][2];
                if(dist[u]!=100000000 && dist[u]+w<dist[v]){
                    return {-1};
                }
        }
        return dist;
    }
};