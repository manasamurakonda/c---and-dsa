// find nth root of an integer
// find nth root of m - GFG
class Solution {
  public:
    int nthRoot(int n, int m) {
        // brute -> linear search
        /*for(int i=0;i<=m;i++)
        {
            if(pow(i,n)==m)
                return i;
            if(pow(i,n)>m)
                break;
        }
        return -1;*/
        
        
        // optimal -> binary search on answers
        int low = 1,high = m;
        while(low<=high)
        {
            int mid = (low+high)/2;
            int x=pow(mid,n);
            if(x==m)
                return mid;
            else if(x>m)
                high = mid-1;
            else low = mid+1;
        }
        return -1;
    }
};