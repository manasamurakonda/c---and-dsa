// n queens-2
// leetcode - 52
class Solution {
public:
    bool check(int row,int col,vector<string> &s,int n)
    {
        for(int i=0;i<col;i++)
        {
            if(s[row][i]=='Q')
                return false;
        }
        int i = row,j=col;
        while(i>=0 && j>=0)
        {
            if(s[i][j]=='Q')
                return false;
            i--;
            j--;
        }
        i=row,j=col;
        while(i<n && j>=0)
        {
            if(s[i][j]=='Q')
                return false;
            i++;
            j--;
        }
        return true;
    }
    void compute(int ind,int n, vector<string> &s,int &ans)
    {
        if(ind == n)
        {
            ans++;
            return;
        }

        for(int i=0;i<n;i++)
        {
            if(check(i,ind,s,n))
            {
                s[i][ind] = 'Q';
                compute(ind+1,n,s,ans);
                s[i][ind] = '.';
            }
        }
    }
    void compute1(int ind,int n,vector<string> &s,int &ans,vector<int> &row,vector<int> &ud,vector<int> &ld)
    {
        if(ind == n)
        {
            ans++;
            return;
        }

        for(int i=0;i<n;i++)
        {
            if(row[i] == 0 && ud[i+ind]==0 && ld[n-1+ind-i]==0)
            {
                row[i] = 1;
                ud[i+ind] = 1;
                ld[n-1+ind-i] = 1;
                s[i][ind] = 'Q';
                compute1(ind+1,n,s,ans,row,ud,ld);
                s[i][ind] = '.';
                row[i] = 0;
                ud[i+ind] = 0;
                ld[n-1+ind-i] = 0;
            }
        }
    }
    int totalNQueens(int n) {
        // brute -> recursion, for loop tc - o(n!*3n) sc-o(n^2)
        /*int ans = 0;
        vector<string> s;
        for(int i=0;i<n;i++)
        {
            string temp = "";
            for(int j=0;j<n;j++)
            {
                temp.push_back('.');
            }
            s.push_back(temp);
        }
        compute(0,n,s,ans);
        return ans;*/

        // optimal -> recursion, hashing, for loop tc-o(n!) sc - o(n^2 + 3n)
        int ans = 0;
        vector<string> s;
        for(int i=0;i<n;i++)
        {
            string temp = "";
            for(int j=0;j<n;j++)
            {
                temp.push_back('.');
            }
            s.push_back(temp);
        }
        vector<int> row(n,0);
        vector<int> ud(2*n-1,0);
        vector<int> ld(2*n-1,0);
        compute1(0,n,s,ans,row,ud,ld);
        return ans;
    }
};