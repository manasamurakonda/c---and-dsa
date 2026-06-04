// accounts merge
// leetcode - 721
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // optimal -> DSU
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int> m;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                if(m.find(accounts[i][j])!=m.end())
                {
                    ds.unionBySize(m[accounts[i][j]],i);
                }
                else m[accounts[i][j]] = i;
            }
        }
        vector<vector<string>> temp;
        temp = accounts;
        for(int i=0;i<n;i++)
        {
            int parent = ds.findUparent(i);
            if(parent != i)
            {
                for(int j=1;j<temp[i].size();j++)
                {
                    temp[parent].push_back(temp[i][j]);
                }
                temp[i] = {};
            }
        }
        for(int i=0;i<n;i++)
        {
            if(temp[i].size()>2)
            sort(temp[i].begin()+1,temp[i].end());
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++)
        {
            int m = temp[i].size();
            if(m>0)
            {
                vector<string> x;
                x.push_back(temp[i][0]);
                for(int j=1;j<m;j++)
                {
                    if(x.back()!=temp[i][j])
                        x.push_back(temp[i][j]);
                }
                ans.push_back(x);
            }
        }
        return ans;
    }
};