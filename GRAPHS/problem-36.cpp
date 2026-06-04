// Find the City With the Smallest Number of Neighbors at a Threshold Distance
// leetcode - 1334
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // optimal -> floyd warshall algo tc-o(n^3) sc-o(n^2)
        int m= edges.size();
        vector<vector<int>> matrix(n,vector<int> (n,INT_MAX));
        for(int i=0;i<n;i++)
        {
            matrix[i][i] = 0;
        }
        for(int i=0;i<m;i++)
        {
            matrix[edges[i][0]][edges[i][1]] = edges[i][2];
            matrix[edges[i][1]][edges[i][0]] = edges[i][2];
        }

        for(int via=0;via<n;via++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(matrix[i][via]!=INT_MAX && matrix[via][j]!=INT_MAX && matrix[i][via]+matrix[via][j]<matrix[i][j])
                        matrix[i][j] = matrix[i][via]+matrix[via][j];
                }
            }
        }

        int ans = -1,mini=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int cnt= 0;
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]<=distanceThreshold)
                    cnt++;
            }
            cout<<cnt<<" ";
            if(cnt<=mini)
            {
                ans = i;
                mini = cnt;
            }
        }
        return ans;
    }
};