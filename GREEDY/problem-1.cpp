// assign cookies
// leetcode - 455

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // optimal -> greedy(sorting) tc-o(nlogn)+o(mlogm)+o(min(n,m)) sc-o(1)
        int n = g.size(),m = s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int j=0,ans=0;
        for(int i=0;i<m && j<n;i++)
        {
            if(s[i]>=g[j]){
                ans++;
                j++;
            }
        }
        return ans;
    }
};