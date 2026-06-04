class Solution {
  public:
    int nCr(int n, int r) {
        long long ans = 1;
        if(r>n)
            return 0;
        if(r==0 || r==n)
            return 1;
        r = min(r,n-r);
        for(int i=0;i<r;i++)
        {
            ans = ans * (n-i);
            ans = ans/(i+1);
        }
        return ans;
    }
};