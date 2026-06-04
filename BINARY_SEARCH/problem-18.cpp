// minimum number of days to make m bouquets
// leetcode - 1482
class Solution {
public:
    int check(vector<int>& bloomDay,int x, int m, int k)
    {
        int ans = 0;
        int count = 0;
        for(int i=0;i<bloomDay.size();i++)
        {
            if(bloomDay[i]<=x)
                count++;
            else 
                count=0;
            if(count==k)
            {
                ans++;
                count=0;
            }
        }
        if(ans>=m)
            return 1;
        return 0;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        // brute -> linear search
        /*int n = bloomDay.size();
        if(m*(long long)k>n)
            return -1;
        int maxi = *max_element(bloomDay.begin(),bloomDay.end()),mini = *min_element(bloomDay.begin(),bloomDay.end());
        for(int i=mini;i<=maxi;i++)
        {
            if(check(bloomDay,i,m,k)==1)
                return i;
        }
        return -1;*/

        // optimal - > binary search
        int n = bloomDay.size();
        int low = *min_element(bloomDay.begin(),bloomDay.end()),high = *max_element(bloomDay.begin(),bloomDay.end());
        if(m*(long long)k>n)
            return -1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(check(bloomDay,mid,m,k)==1)
                high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};