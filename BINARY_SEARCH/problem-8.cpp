// count occurrences in sorted array
class Solution {
public:
    int lb(vector<int> &arr,int target)
    {
        int n = arr.size(),low = 0,high = n-1,ans = -1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(arr[mid]>=target)
            {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
    int ub(vector<int> &arr,int target)
    {
        int n = arr.size(),low = 0,high = n-1,ans = -1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(arr[mid]>target)
            {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
    int countOccurrences(vector<int>& arr, int target) {
        // brute -> linear search
        /*int ans = 0,n=arr.size();
        for(int i=0;i<n;i++)
        {
            if(arr[i]==target)
                ans++;
        }
        return ans;*/

        // optimal1 -> binary search(upperbound and lower bound-1)
        int first = lb(arr,target);
        if(first == -1 || arr[first]!=target)
            return 0;
        int last = ub(arr,target);
        if(last == -1)
            last = arr.size();
        last--;
        return last-first+1;

        //optimal2 -> use pure binary search to find last and first occurance  like in last problem
    }
};