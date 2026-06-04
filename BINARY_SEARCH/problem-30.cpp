// search a 2D matrix
// leetcode - 74
class Solution {
public:
    bool bs(vector<int> nums,int target)
    {
        int n = nums.size();
        int low = 0,high = n-1;
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
        // brute -> linear search

        // better -> iterating over all rows and doing bs on the answer row
        /*int n = matrix.size(),m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            if(matrix[i][0]<=target && matrix[i][m-1]>=target)
                return bs(matrix[i],target);
        }
        return false;*/

        // optimal(my optimal) -> binary search on all rows and answer row tc = o(log n +log m)
        /*int n=matrix.size(),m=matrix[0].size();
        int low = 0,high = n-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(matrix[mid][0]==target || matrix[mid][m-1]==target)
                return true;
            else if(target > matrix[mid][0] && target < matrix[mid][m-1])
            {
                return bs(matrix[mid],target);
            }
            else if(target<matrix[mid][0])
            {
                high = mid-1;
            }
            else low = mid+1;
        }
        return false;*/

        // optimal2 -> strivers optimal (flattening the 2d matrix to perform binary search)
        int n = matrix.size(),m=matrix[0].size();
        int low = 0,high = n*m-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(matrix[mid/m][mid%m]==target)
                return true;
            else if(matrix[mid/m][mid%m]>target)
                high = mid-1;
            else low = mid+1;
        }
        return false;
    }
};