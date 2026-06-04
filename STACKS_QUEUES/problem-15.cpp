// GFG - the celebrity problem

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // brute -> hashing tc-o(n^2)+o(n) sc-o(n)
        /*int n  = mat.size();
        vector<int> hash(n,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j && mat[i][j]==1)
                    hash[i]=-1;
                if(mat[i][j]==0)
                    hash[j]=-1;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(hash[i]==0)
                return i;
        }
        return -1;*/
        
        // there is a stack approach which i havent done yet
        
        // optimal -> two pointer approach tc-o(2n) sc-o(1)
        int n = mat.size();
        int low = 0,high = n-1;
        while(low<high)
        {
            if(mat[low][high]==1)
                low++;
            else if(mat[high][low]==1)
                high--;
            else{
                low++;
                high--;
            }
        }
        if(low>high)
            return -1;
        for(int i=0;i<n;i++)
        {
            if(mat[low][i]==1 && low!=i)
                return -1;
            if(mat[i][low]!=1)
                return -1;
        }
        return low;
    }
};