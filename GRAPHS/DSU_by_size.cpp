#include<bits/stdc++.h>
using namespace std;
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
int main()
{
    DisjointSet ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    if(ds.findUparent(3)==ds.findUparent(7))
        cout<<"same"<<endl;
    else cout<<"not same"<<endl;
    ds.unionBySize(3,7);
    if(ds.findUparent(3)==ds.findUparent(7))
        cout<<"same"<<endl;
    else cout<<"not same"<<endl;
    return 0;
}