// koko eating bananas
// leetcode - 875
class Solution {
public:
    int check(vector<int>& piles, int h,int mid)
    {
        long long hours = 0;
        for(int i=0;i<piles.size();i++)
        {
            hours = hours + ceil(piles[i]/(double)mid);
            if(hours>h)
                return 0;
        }
        return 1;
    } 
    int minEatingSpeed(vector<int>& piles, int h) {
        // brute -> linear search
        /*int maxi=*max_element(piles.begin(),piles.end());
        for(int i=1;i<=maxi;i++)
        {
            if(check(piles,h,i)==1)
                return i;
        }
        return -1;*/
        int maxi=*max_element(piles.begin(),piles.end());
        int low = 1,high = maxi;
        while(low<=high)
        {
            int mid = (low+high)/2;
            int x= check(piles,h,mid);
            if(x==1)
                high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};