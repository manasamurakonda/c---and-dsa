// rotate image or rotate matrix by 90 degrees leetcode-48
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // brute -> use another matrix 
        /*int n = matrix.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            vector<int> temp;
            for(int j=n-1;j>=0;j--)
            {
                temp.push_back(matrix[j][i]);
            }
            ans.push_back(temp);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                matrix[i][j] = ans[i][j];
            }
        }*/

        // optimal - > something like transpose and reverse
        int n = matrix.size();
        int low,high;
        for(int i=0;i<n;i++)
        {
            low = 0,high = n-1;
            while(low<=high)
            {
                swap(matrix[low][i],matrix[high][i]);
                low++;
                high--;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i<j)
                {
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
        }
    }
};