// maximum consecutive ones leetcode-485

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // brute - nested loops
        /* int n = nums.size();
        int count = 0;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                for(int j=i;j<n;j++)
                {
                    if(nums[j]==1)
                        count++;
                    else
                        break;
                }
                ans = max(ans,count);
                count = 0;
            }
        }
        return ans; */

        // optimal one loop - one pointer

        int n = nums.size();
        int count = 0,ans =0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] == 1)
                count++;
            else{
                ans = max(ans,count);
                count = 0;
            }
        }
        ans = max(ans,count);
        return ans;
    }
};