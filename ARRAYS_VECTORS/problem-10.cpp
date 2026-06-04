// missing number leetcode - 268

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        // brute - > rendu loops eyyi
        /* for(int i=0;i<=n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(nums[j]==i)
                    break;
                else if(j==n-1)
                    return i;
            }
        }
        return -1; */

        // better - use hashing

        // optimal-1 n*(n+1)/2
        /* int ans = n*(n+1)/2;
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum = sum + nums[i];
        }
        return ans-sum; */

        // optimal-2 xor operator
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            ans = ans ^ i ^ nums[i];
        }
        ans = ans ^ n;
        return ans;
    }
};