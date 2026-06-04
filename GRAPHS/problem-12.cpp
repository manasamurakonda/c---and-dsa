// checking if a graph is bipartite using DFS
// leetcode - 785
class Solution {
public:
    bool dfs(int cur,vector<vector<int>>& graph,vector<int> &colour)
    {
        for(auto it : graph[cur])
        {
            if(colour[it] == -1)
            {
                colour[it] = !colour[cur];
                if(dfs(it,graph,colour)==false)
                    return false;
            }
            else{
                if(colour[it] == colour[cur])
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        // optimal -> try to colour graph using two colours tc-o(V+2E) sc-o(V)
        int n = graph.size();
        vector<int> colour(n,-1);
        for(int i=0;i<n;i++)
        {
            if(colour[i]==-1)
            {
                colour[i] = 0;
                if(dfs(i,graph,colour)==false)
                    return false;
            }
        }
        return true;
    }
};