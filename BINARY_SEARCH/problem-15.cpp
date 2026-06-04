// sqrt of an integer
// leetcode - 69
class Solution {
public:
    int mySqrt(int x) {
        // brute -> linear search
        /*for(long long i=0;i<=x;i++)
        {
            if(i*i==x)
                return i;
            else if(i*i>x)
                return i-1;
        }
        return -1;*/

        // optimal -> binary search on answers
        int low = 0,high = x;
        while(low<=high)
        {
            long long mid = (low+high)/2;
            if(mid*mid == x)
                return mid;
            else if(mid*mid>x)
                high = mid-1;
            else low = mid+1;
        }
        return high;
    }
};