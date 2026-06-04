// number of provinces
// leetcode - 547
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        // optimal -> dsu tc-o(n^2+n) sc-o(2n)
        int n = isConnected.size(),ans=0;
        DisjointSet ds(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1)
                {
                    if(ds.findUparent(i)!=ds.findUparent(j))
                    {
                        ds.unionBySize(i,j);
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(ds.findUparent(i)==i)
                ans++;
        }
        return ans;
    }
};