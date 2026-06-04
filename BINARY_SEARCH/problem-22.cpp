// aggressive cows - GFG
class Solution {
  public:
    int check(vector<int> &stalls, int k, int x)
    {
        int dist = stalls[0],cows = 0;
        for(int i=0;i<stalls.size();i++)
        {
            if(stalls[i]-dist>=x || i==0)
            {
                dist=stalls[i];
                cows++;
            }
        }
        if(cows>=k)
            return 1;
        return 0;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        // brute -> linear iteration, sort chesinaka
        /*sort(stalls.begin(),stalls.end());
        int n = stalls.size();
        for(int i=1;i<=(stalls[n-1]-stalls[0]);i++)
        {
            if(check(stalls,k,i)==1)
                ans = i;
            else break;
        }
        return ans;*/
        
        // optimal -> binary search on answers min(max)
        int n = stalls.size();
        sort(stalls.begin(),stalls.end());
        int low = 1,high = stalls[n-1]-stalls[0];
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(check(stalls,k,mid)==1)
                low = mid+1;
            else high=mid-1;
        }
        return high;
    }
};