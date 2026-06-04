// GFG - N meetings in one room

class Solution {
  public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // optimal -> greedy(sorting) tc-o(nlogn)+o(2n) sc-o(2n)
        int n = start.size();
        vector<pair<int,int>> pr;
        for(int i=0;i<n;i++)
            pr.push_back({start[i],end[i]});
        sort(pr.begin(),pr.end(),[&](pair<int,int> &x,pair<int,int> &y){
            return x.second<y.second;
        });
        int last=-1,ans=0;
        for(int i=0;i<n;i++)
        {
            if(last<pr[i].first)
            {
                last = pr[i].second;
                ans++;
            }
        }
        return ans;
    }
};