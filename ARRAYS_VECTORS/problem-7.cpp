// best time to buy and sell stocks
// leetcode-121
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // brute
        /* int n=prices.size();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(prices[i]<prices[j])
                {
                    ans=max(ans,abs(prices[i]-prices[j]));
                }
            }
        }
        return ans; */

        // better -> two arrays vadi cheyyochemo aalochinchu
        //dhanney prefix sum ani kuda antaru anukunta
        /*int n = prices.size();
        int ans = 0;
        int small = INT_MAX;
        int big = INT_MIN;
        vector<int> left;
        vector<int> right;
        for(int i=0;i<n;i++)
        {
            if(small>prices[i])
                small = prices[i];
            if(big < prices[n-1-i])
                big = prices[n-1-i];
            left.push_back(small);
            right.push_back(big);
        }
        reverse(right.begin(),right.end());
        for(int i=0;i<n;i++)
        {
            ans = max(ans,abs(right[i]-left[i]));
        }
        return ans;*/

        // there is an optimal which u cant think of....u dumb
        //optimal -> think of if u are on ith index...whom you have to compare(minimum element till i-1 th index)
        int n = prices.size();
        int ans = 0, mini = prices[0];
        for(int i=1;i<n;i++)
        {
            ans = max(ans,prices[i]-mini);
            if(prices[i]<mini)
                mini = prices[i];
        }
        return ans;
    }
};