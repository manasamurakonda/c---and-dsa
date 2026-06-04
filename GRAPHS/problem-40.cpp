// number of operations to make network connected
// leetcode - 1319
class DisjointSet{
    vector<int> parent,size;
    public:
    DisjointSet(int n)
    {
        size.resize(n+1,1);
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        // optimal -> DSU tc-o(n+4alpha) sc-o(n)
        int m = connections.size(),cnt=0;
        DisjointSet ds(n);
        for(int i=0;i<m;i++)
        {
            int x = connections[i][0], y = connections[i][1];
            if(ds.findUparent(x) != ds.findUparent(y))
            {
                ds.unionBySize(x,y);
            }
            else{
                cnt++;
            }
        }
        int conn = 0;
        for(int i=0;i<n;i++)
        {
            if(ds.findUparent(i)==i)
                conn++;
        }
        conn = conn - 1;
        if(conn>cnt)
            return -1;
        return conn;
    }
};