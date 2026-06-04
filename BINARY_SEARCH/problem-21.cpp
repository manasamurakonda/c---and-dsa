// kth missing positive number
// leetcode - 1539
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // brute1-> my brute
        /*int n = arr.size(),x=0;
        for(int i=0;i<n;i++)
        {
            if(i==0)
                x=x+arr[i]-1;
            else 
                x=x+(arr[i]-arr[i-1]-1);
            if(x==k)
                return arr[i]-1;
            if(x>k)
            {
                return arr[i]-(x-k)-1;
            }
        }
        return arr[n-1]+(k-x);*/

        // brute 2 -> strivers brute
        /*int n = arr.size(),x=k;
        for(int i=0;i<n;i++)
        {
            if(arr[i]<=x)
                x++;
            else break;
        }
        return x;*/

        // optimal -> binary search
        int n = arr.size();
        int low = 0,high = n-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(arr[mid]-(mid+1)>=k)
                high = mid-1;
            else low = mid+1;
        }
        return low+k;
    }
};