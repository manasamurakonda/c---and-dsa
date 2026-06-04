// row with maximum 1's - GFG
class Solution {
  public:
    int bs(vector < vector < int >> & mat,int ind)
    {
        int m = mat[0].size();
        int low = 0,high = m-1;
        while(low<=high)
        {
        int mid = (low+high)/2;
        if(mat[ind][mid]==0)
            low = mid+1;
        else high = mid-1;
        }
        return m-low;
    }
    int rowWithMax1s(vector<vector<int>> &mat) {
        // brute -> iterating over the complete matrix

        // optimal -> binary searching every row
        int n=mat.size(),m=mat[0].size();
        int cnt = 0,ans = -1;
        for(int i=0;i<n;i++)
        {
        int x = bs(mat,i);
        if(cnt<x)
        {
            cnt = x;
            ans = i;
        }
        }
        return ans;
    }
};