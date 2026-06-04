#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cout<<"enter no.of nodes: ";
    cin>>n;
    cout<<"enter no.of edges: ";
    cin>>m;
    vector<int> adj[n+1];
    cout<<"enter edges: "<<endl;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout<<"the adjacency list is : "<<endl;
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}