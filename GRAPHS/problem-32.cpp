// GFG - Minimum Multiplications to reach End
class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // optimal -> bfs tc-o(10^5) sc-o(10^5)
        int n =arr.size();
        vector<bool> visited(100000,false);
        queue<pair<int,int>> q;
        q.push({0,start%100000});
        visited[start%100000] = true;
        while(!q.empty())
        {
            int cur = q.front().second;
            int steps = q.front().first;
            q.pop();
            if(cur == end)
                return steps;
            for(auto it : arr)
            {
                int val = (cur*it)%100000;
                if(val == end)
                    return steps+1;
                if(!visited[val])
                {
                    visited[val] = true;
                    q.push({steps+1,val});
                }
            }
        }
        return -1;
    }
};
