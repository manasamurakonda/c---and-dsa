// spiral matrix
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // optimal - > four pointers
        int n=matrix.size(),m=matrix[0].size();
        int right = 0,down = m-1,left = n-1,up = 0;
        vector<int> ans;
        while(right<=left && up<=down)
        {
            for(int i=up;i<=down && (right<=left && up<=down);i++)
            {
                ans.push_back(matrix[right][i]);
            }
            right++;
            
            for(int i=right;i<=left && (right<=left && up<=down);i++)
            {
                ans.push_back(matrix[i][down]);
            }
            down--;
            
            for(int i=down;i>=up && (right<=left && up<=down);i--)
            {
                ans.push_back(matrix[left][i]);
            }
            left--;
            
            for(int i=left;i>=right && (right<=left && up<=down);i--)
            {
                ans.push_back(matrix[i][up]);
            }
            up++;
        }
        return ans;
    }
};