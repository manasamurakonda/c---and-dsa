// GFG - Dijkstra
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // optimal -> dijkstra using set tc-o(ElogV) sc-o(V^2)
        vector<vector<pair<int,int>>> adj(V);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        vector<int> ans(V,INT_MAX);
        set<pair<int,int>> st;
        st.insert({0,src});
        ans[src] = 0;
        while(!st.empty())
        {
            int cur = (*st.begin()).second;
            int dist = (*st.begin()).first;
            st.erase(*st.begin());
            if(dist<ans[cur])
                continue;
            for(auto it : adj[cur])
            {
                if(it.second+dist<ans[it.first])
                {
                    if(ans[it.first]!=INT_MAX)
                        st.erase({ans[it.first],it.first});
                    ans[it.first] = it.second+dist;
                    st.insert({ans[it.first],it.first});
                }
            }
        }
        return ans;
    }
};