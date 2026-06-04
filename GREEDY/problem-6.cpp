// GFG - Job Sequencing Problem

class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // brute -> greedy(sorting) tc-o(nlogn)+o(n*maxdeadline) sc-o(3n) 
        int n = profit.size(),prof=0,jobs=0;
        int maxi = *max_element(deadline.begin(),deadline.end());
        vector<int> allocation(maxi,0);
        vector<pair<int,int>> pr;
        for(int i=0;i<n;i++)
        {
            pr.push_back({deadline[i],profit[i]});
        }
        sort(pr.begin(),pr.end(),[&](pair<int,int> x,pair<int,int> y)
        {
           return x.second>y.second; 
        });
        for(int i=0;i<n;i++)
        {
            int end=pr[i].first-1;
            while(allocation[end]==1 && end>=0)
                end--;
            if(end>=0)
            {
                allocation[end]=1;
                prof = prof+pr[i].second;
                jobs++;
            }
        }
        return {jobs,prof};
        
        // better -> min heap +sorting tc-o(nlogn) sc-o(n)
        
        // optimal -> disjoint set tc-o(nlogd) sc-o(d)
    }
};