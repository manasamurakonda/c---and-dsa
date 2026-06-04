// sum of subarray ranges
// leetcode - 2104

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        // brute -> nested loops tc-o(n^2) sc-o(1)
        /*int n= nums.size();
        long long ans = 0;
        for(int i=0;i<n;i++)
        {
            long long mini = INT_MAX;
            long long maxi = INT_MIN;
            for(int j=i;j<n;j++)
            {
                mini = min(mini,(long long)nums[j]);
                maxi = max(maxi,(long long)nums[j]);
                ans = ans+maxi-mini;
            }
        }
        return ans;*/

        // optimal -> monotonic stack tc-o(6n) sc-o(6n)
        int n = nums.size();
        vector<int> nse(n,n);
        vector<int> pse(n,-1);
        vector<int> nge(n,n);
        vector<int> pge(n,-1);
        stack<pair<int,int>> st1,st2;
        for(int i=n-1;i>=0;i--)
        {
            while(!st1.empty() && st1.top().first>=nums[i])
                st1.pop();
            if(!st1.empty())
                nse[i] = st1.top().second;
            st1.push({nums[i],i});
            while(!st2.empty() && st2.top().first<=nums[i])
                st2.pop();
            if(!st2.empty())
                nge[i] = st2.top().second;
            st2.push({nums[i],i});
        }
        while(!st1.empty())
            st1.pop();
        while(!st2.empty())
            st2.pop();
        for(int i=0;i<n;i++)
        {
            while(!st1.empty() && st1.top().first>nums[i])
                st1.pop();
            if(!st1.empty())
                pse[i] = st1.top().second;
            st1.push({nums[i],i});
            while(!st2.empty() && st2.top().first<nums[i])
                st2.pop();
            if(!st2.empty())
                pge[i] = st2.top().second;
            st2.push({nums[i],i});
        }
        long long ans1=0,ans2=0;
        for(int i=0;i<n;i++)
        {
            ans1 = ans1 +((long long)nums[i]*(long long)(i-pge[i])*(long long)(nge[i]-i));
            ans2 = ans2 + ((long long)nums[i]*(long long)(i-pse[i])*(long long)(nse[i]-i));
        }
        return ans1-ans2;
    }
};