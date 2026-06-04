// GFG - shortest job first

class Solution {
  public:
    long long solve(vector<int>& bt) {
        // optimal -> greedy(sorting) tc-o(nlogn)+o(n) sc-o(1)
        long long n = bt.size();
        long long sum =0,ans =0;
        sort(bt.begin(),bt.end());
        for(int i=0;i<n;i++)
        {
          ans = ans + sum;
          sum = sum + bt[i];
        }
        return floor(ans/n);
    }
};