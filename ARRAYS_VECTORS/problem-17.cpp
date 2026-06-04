// leaders in an array
// Array Leaders in geeks for geeks

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // brute nested loops
        /*int n = arr.size();
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(arr[i]<arr[j])
                    break;
                if(j==n-1)
                    ans.push_back(arr[i]);
            }
        }
        return ans;*/
        // better - > o(2n) // optimal
        int maxi = 0;
        vector<int> ans;
        int n = arr.size();
        for(int i=n-1;i>=0;i--)
        {
            if(maxi<arr[i])
                maxi = arr[i];
            if(maxi == arr[i])
                ans.push_back(arr[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};