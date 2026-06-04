// jump game -2
// leetcode - 45

class Solution {
public:
    int jump(vector<int>& nums) {
        // brute -> can solve it using recursion and dp which i havent studied yet

        // better -> prefix sum kind of tc-o(2n) sc-o(n)
        /*int n = nums.size();
        if(n==1)
            return 0;
        vector<int> ps;
        int maxi = 0;
        ps.push_back(0);
        for(int i=0;i<n;i++)
        {
            for(int j=ps.size();j<=i+nums[i] && j<n;j++)
                ps.push_back(ps[i]+1);
            if(i+nums[i]>=n-1)
                return ps[i]+1;
        }
        return -1;*/


        // optimal -> greedy(range and farthest jump in that range) tc-o(n) sc-o(1)
        int n = nums.size(),low=0,high=0,jumps=0,far=0;
        while(high<n-1)
        {
            far = 0;
            for(int i=low;i<=high;i++)
                far = max(far,nums[i]+i);
            low = high+1;
            high = far;
            jumps++;
        }
        return jumps;
    }
};