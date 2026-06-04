// GFG - Minimum Platforms

class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        
        // brute -> nested loops which i haven't understood clearly (pending)
        
        // optimal -> greedy(sorting and two pointers) tc-o(2nlogn)+o(2n) sc-o(1)
        int n = arr.size(),cnt=0,maxi=0,l1=0,l2=0;
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        while(l1<n)
        {
            if(arr[l1]<=dep[l2])
            {
                cnt++;
                l1++;
            }
            else{
                cnt--;
                l2++;
            }
            maxi = max(maxi,cnt);
        }
        return maxi;
    }
};
