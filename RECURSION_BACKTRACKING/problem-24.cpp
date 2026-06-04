// palindrome partitioning
// leetcode - 131
class Solution {
public:
    bool check(string &s)
    {
        int n = s.size();
        int low = 0,high = n-1;
        while(low<high)
        {
            if(s[low]!=s[high])
                return false;
            low++;
            high--;
        }
        return true;
    }
    void compute(int ind,int n,string &s,vector<vector<string>> &ans,vector<string> &temp)
    {
        if(ind == n)
        {
            ans.push_back(temp);
            return;
        }

        string str = "";
        for(int i=ind;i<n;i++)
        {
            str.push_back(s[i]);
            if(check(str))
            {
                temp.push_back(str);
                compute(i+1,n,s,ans,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        // optimal -> backtracking
        int n = s.size();
        vector<vector<string>> ans;
        vector<string> temp;
        compute(0,n,s,ans,temp);
        return ans;
    }
};