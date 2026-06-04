// longest common substring
// leetcode - 718 Maximum Length of Repeated Subarray
class Solution {
public:
    int recursion(int ind1,int ind2,vector<int> &nums1,vector<int> &nums2,int count)
    {
        if(ind1<0 || ind2<0)
            return count;
        int x=count,y=0,z=0;
        if(nums1[ind1]==nums2[ind2])
            x = recursion(ind1-1,ind2-1,nums1,nums2,count+1);
        y = recursion(ind1-1,ind2,nums1,nums2,0);
        z = recursion(ind1,ind2-1,nums1,nums2,0);
        return max(x,max(y,z));
    }
    int memoization(int ind1,int ind2,vector<int> &nums1,vector<int> &nums2,int count,vector<vector<vector<int>>> &dp)
    {
        if(ind1<0 || ind2<0)
            return count;
        if(dp[ind1][ind2][count]!=-1)
            return dp[ind1][ind2][count];
        int x=count,y=0,z=0;
        if(nums1[ind1]==nums2[ind2])
            x = memoization(ind1-1,ind2-1,nums1,nums2,count+1,dp);
        y = memoization(ind1-1,ind2,nums1,nums2,0,dp);
        z = memoization(ind1,ind2-1,nums1,nums2,0,dp);
        return dp[ind1][ind2][count] =  max(x,max(y,z));
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // recursion
        /*int n1 = nums1.size(),n2 = nums2.size();
        return recursion(n1-1,n2-1,nums1,nums2,0);*/

        // memoization
        /*int n1 = nums1.size(),n2 = nums2.size();
        vector<vector<vector<int>>> dp(n1,vector<vector<int>> (n2,vector<int> (max(n1,n2),-1)));
        return memoization(n1-1,n2-1,nums1,nums2,0,dp);*/

        // tabulation
        /*int n1 = nums1.size(),n2 = nums2.size();
        vector<vector<vector<int>>> dp(n1+1,vector<vector<int>> (n2+1,vector<int> (min(n1,n2)+1,-1)));
        for(int ind=0;ind<=n2;ind++)
        {
            for(int count=0;count<=min(n1,n2);count++)
            {
                dp[0][ind][count] = count;
            }
        }
        for(int ind=0;ind<=n1;ind++)
        {
            for(int count=0;count<=min(n1,n2);count++)
            {
                dp[ind][0][count] = count;
            }
        }

        for(int ind1=1;ind1<=n1;ind1++)
        {
            for(int ind2=1;ind2<=n2;ind2++)
            {
                for(int count=min(n1,n2)-1;count>=0;count--)
                {
                    int x=count,y=0,z=0;
                    if(nums1[ind1-1]==nums2[ind2-1])
                        x = dp[ind1-1][ind2-1][count+1];
                    y = dp[ind1-1][ind2][0];
                    z = dp[ind1][ind2-1][0];
                    dp[ind1][ind2][count] =  max(x,max(y,z));
                }
            }
        }
        return dp[n1][n2][0];*/

        // space optimization still gives tle
        /*int n1 = nums1.size(),n2 = nums2.size();
        vector<vector<int>> prev(n2+1,vector<int> (min(n1,n2)+1,0));
        for(int ind=0;ind<=n2;ind++)
        {
            for(int count=0;count<=min(n1,n2);count++)
            {
                prev[ind][count] = count;
            }
        }
        vector<vector<int>> cur = prev;
        for(int ind1=1;ind1<=n1;ind1++)
        {
            for(int ind2=1;ind2<=n2;ind2++)
            {
                for(int count=min(n1,n2)-1;count>=0;count--)
                {
                    int x=count,y=0,z=0;
                    if(nums1[ind1-1]==nums2[ind2-1])
                        x = prev[ind2-1][count+1];
                    y = prev[ind2][0];
                    z = cur[ind2-1][0];
                    cur[ind2][count] =  max(x,max(y,z));
                }
            }
            prev = cur;
        }
        return prev[n2][0];*/

        // better -> 2d dp tabulation
        /*int n1 = nums1.size(),n2=nums2.size();
        vector<vector<int>> dp(n1+1,vector<int> (n2+1,0));
        int ans = 0;
        for(int ind1=1;ind1<=n1;ind1++)
        {
            for(int ind2=1;ind2<=n2;ind2++)
            {
                if(nums1[ind1-1]==nums2[ind2-1])
                    dp[ind1][ind2] = 1+dp[ind1-1][ind2-1];
                else dp[ind1][ind2] = 0;
                ans = max(ans,dp[ind1][ind2]);
            }
        }
        return ans;*/

        // optimal -> 2d dp space optimization
        int n1 = nums1.size(),n2=nums2.size();
        vector<int> prev(n2+1,0),cur(n2+1,0);
        int ans = 0;
        for(int ind1=1;ind1<=n1;ind1++)
        {
            for(int ind2=1;ind2<=n2;ind2++)
            {
                if(nums1[ind1-1]==nums2[ind2-1])
                    cur[ind2] = 1+prev[ind2-1];
                else cur[ind2] = 0;
                ans = max(ans,cur[ind2]);
            }
            prev = cur;
        }
        return ans;
    }
};