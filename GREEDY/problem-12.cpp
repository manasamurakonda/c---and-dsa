// GFG - fractional knapsack

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // optimal -> greedy(sorting) tc-o(nlogn)+o(n) sc-o(3n)
        
        vector<pair<pair<int,int>,double>> pr;
        int n = val.size();
        for(int i=0;i<n;i++)
            pr.push_back({{val[i],wt[i]},(double)val[i]/(double)wt[i]});
        sort(pr.begin(),pr.end(),[&](pair<pair<int,int>,double> &x,pair<pair<int,int>,double> &y){
            return x.second>y.second;
        });
        double ans=0;
        int w=0;
        for(int i=0;i<n;i++)
        {
            if(pr[i].first.second+w<=capacity)
            {
                ans = ans + pr[i].first.first;
                w = w + pr[i].first.second;
            }
            else{
                ans = ans + (pr[i].first.first)*((double)(capacity-w)/(double)pr[i].first.second);
                break;
            }
        }
        return ans;
    }
};
