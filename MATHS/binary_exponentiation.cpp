// leetcode - 50
class Solution {
public:
    double myPow(double x, int n) {
        long long n1 = n;
        if(n<0)
        {
            n1 = -1*n1;
        }
        double ans = 1;
        while(n1>0)
        {
            if(n1%2==0)
            {
                x=x*x;
                n1 = n1/2;
            }
            else{
                ans = ans*x;
                n1 = n1-1;
            }
        }
        if(n<0)
            ans = 1.0/ans;
        return ans;
    }
};