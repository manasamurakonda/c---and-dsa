// pascal triangle leetcode-118
class Solution {
public:
    int ncr(int n,int r)
    {
        long long ans = 1;
        if(r>n)
            return 0;
        if(r==0 || r==n)
            return 1;
        r = min(r,n-r);
        for(int i=0;i<r;i++)
        {
            ans=ans*(n-i);
            ans=ans/(i+1);
        }
        return ans;
    }
    vector<vector<int>> generate(int numRows) {
        // brute -> using ncr formula
        /*vector<vector<int>> ans;
        int n = numRows;
        for(int i=1;i<=n;i++)
        {
            vector<int> temp;
            for(int j=1;j<=i;j++)
            {
                temp.push_back(ncr(i-1,j-1));
            }
            ans.push_back(temp);
        }
        return ans;*/
        // optimal -> use the approach u used to generate row
        vector<vector<int>> result;
        int n =numRows;
        for(int i=1;i<=n;i++)
        {
            vector<int> temp;
            int ans = 1;
            for(int j=0;j<i;j++)
            {
                if(j==0)
                    ans = 1;
                else
                    ans = ans*(i-j)/j;
                temp.push_back(ans);
            }
            result.push_back(temp);
        }
        return result;
    }
};