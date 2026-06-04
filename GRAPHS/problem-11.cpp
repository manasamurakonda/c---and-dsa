// bipartite graph check using BFS
// leetcode - 785
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // optimal -> try to colour graph using two colours tc-o(V+2E) sc-o(V)
        int n = graph.size();
        vector<int> colour(n,-1);
        queue<int> q;
        for(int i=0;i<n;i++){
            if(colour[i] == -1)
            {
                colour[i] = 0;
                q.push(i);
            }
            while(!q.empty())
            {
                int cur = q.front();
                q.pop();
                int clr = colour[cur];
                for(int j=0;j<graph[cur].size();j++)
                {
                    if(colour[graph[cur][j]] == -1)
                    {
                        colour[graph[cur][j]] = !clr;
                        q.push(graph[cur][j]);
                    }
                    else{
                        if(colour[graph[cur][j]] == colour[cur])
                            return false;
                    }
                }
            }
        }
        return true;
    }
};