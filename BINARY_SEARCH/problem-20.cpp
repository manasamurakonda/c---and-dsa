// capacity to ship packages within d days
// leetcode - 1011
class Solution {
public:
    int check(vector<int>& weights, int days,int x)
    {
        int d=0,sum=0,n=weights.size();
        for(int i=0;i<n;i++)
        {
            sum = sum + weights[i];
            if(sum>x)
            {
                d++;
                sum=weights[i];
            }
        }
        if(sum>0)
            d++;
        if(d<=days)
            return 1;
        return 0;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        // brute -> linear search
        /*int sum = accumulate(weights.begin(),weights.end(),0);
        int maxi = *max_element(weights.begin(),weights.end());
        for(int i=maxi;i<=sum;i++)
        {
            if(check(weights,days,i)==1)
                return i;
        }
        return -1;*/

        // optimal -> binary search
        int high = accumulate(weights.begin(),weights.end(),0);
        int low = *max_element(weights.begin(),weights.end());
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(check(weights,days,mid)==1)
                high = mid-1;
            else low = mid +1;
        }
        return low;
    }
};