// merge overlapping intervals
// leetcode->56 
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // optimal -> sort chey mawa
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        int low = intervals[0][0],high = intervals[0][1];
        vector<vector<int>> ans;
        for(int i=1;i<n;i++)
        {
            int x = intervals[i][0];
            int y = intervals[i][1];
            if(low<=x && high>=x)
            {
                high = max(high,y);
            }
            else{
                ans.push_back({low,high});
                low = x;
                high = y;
            }
        }
        ans.push_back({low,high});
        return ans;
    }
};