// GFG - Minimum Spanning Tree - Kruskal's Algorithm
class DisjointSet{
    vector<int> parent,size;
    public:
    DisjointSet(int n)
    {
        size.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<n+1;i++)
            parent[i] = i;
    }

    int findUparent(int u)
    {
        if(parent[u] == u)
            return u;
        return parent[u] = findUparent(parent[u]);
    }

    void unionBySize(int u,int v)
    {
        int ulp_u = findUparent(u), ulp_v = findUparent(v);
        if(ulp_u == ulp_v)
            return;
        if(size[ulp_u]<size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] = size[ulp_v]+ size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] = size[ulp_u]+ size[ulp_v];
        }
    }
};
class Solution {
  public:
    static bool compare(vector<int> &a,vector<int> &b)
    {
        if(a[2]<b[2])
            return true;
        return false;
    }
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // tc - o(nlogn) + o(n*4 alpha)
        // sc - o(2n)
        int tot_wt = 0;
        DisjointSet ds(V);
        vector<vector<int>> ans;
        sort(edges.begin(),edges.end(),compare);
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            if(ds.findUparent(u) != ds.findUparent(v))
            {
                ds.unionBySize(u,v);
                tot_wt = tot_wt + w;
                ans.push_back({u,v,w});
            }
        }
        return tot_wt;
    }
};