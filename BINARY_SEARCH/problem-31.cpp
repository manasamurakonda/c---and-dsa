// search a 2D matrix 2
// leetcode - 240
class Solution {
public:
    bool bs(vector<int> nums,int target)
    {
        int low = 0,high = nums.size()-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(nums[mid]==target)
                return true;
            else if(nums[mid]>target)
                high = mid-1;
            else low = mid+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // brute -> linear iteration

        // better -> o(nlogm)
        /*int n = matrix.size(),m = matrix[0].size();
        for(int i=0;i<n;i++)
        {
            if(matrix[i][0]<=target && matrix[i][m-1]>=target)
            {
                if(bs(matrix[i],target))
                    return true;
            }
        }
        return false;*/

        // optimal -> you know...kind of start from [0][m-1] element
        int n = matrix.size(),m = matrix[0].size();
        int row = 0,col = m-1;
        while(row<n && col>=0)
        {
            if(matrix[row][col]==target)
                return true;
            else if(matrix[row][col]>target)
                col--;
            else row++;
        }
        return false;
    }
};