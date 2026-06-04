// insert interval
// leetcode - 57

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // optimal -> greedy tc-o(n) sc-o(1)
        int n = intervals.size(),l=newInterval[0],r=newInterval[1];
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            if(l==-1 && r==-1)
            {
                ans.push_back({intervals[i][0],intervals[i][1]});
            }
            else if(intervals[i][0]>r)
            {
                ans.push_back({l,r});
                ans.push_back({intervals[i][0],intervals[i][1]});
                l=-1;
                r=-1;
            }
            else if(intervals[i][1]<l)
            {
                ans.push_back({intervals[i][0],intervals[i][1]});
            }
            else{
                l = min(l,intervals[i][0]);
                r = max(r,intervals[i][1]);
            }
        }
        if(l!=-1 && r!=-1)
            ans.push_back({l,r});
        return ans;
    }
};