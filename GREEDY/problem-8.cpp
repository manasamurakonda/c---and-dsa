// non overlapping intervals
// leetcode - 435

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // optimal -> greedy(sorting) tc-o(nlogn)+o(2n) sc-o(2n)
        int n = intervals.size();
        vector<pair<int,int>> pr;
        for(int i=0;i<n;i++)
            pr.push_back({intervals[i][0],intervals[i][1]});
        sort(pr.begin(),pr.end(),[&](pair<int,int> &x,pair<int,int> &y)
        {
            return x.second<y.second;
        });
        int last=INT_MIN,ans=0;
        for(int i=0;i<n;i++)
        {
            if(pr[i].first<last)
                ans++;
            else
                last = pr[i].second;
        }
        return ans;
    }
};