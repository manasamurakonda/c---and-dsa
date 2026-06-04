// jump game 
// leetcode - 55

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // optimal -> greedy(keeping track of max ind we can reach) tc-o(n) sc-o(1)
        int n = nums.size();
        int maxi = 0;
        int i=0;
        while(i<=maxi && i<n)
        {
            if(maxi>=n-1)
                return true;
            maxi = max(maxi,i+nums[i]);
            i++;
        }
        return false;
    }
};