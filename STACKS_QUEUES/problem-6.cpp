// trapping rainwater
// leetcode - 42

class Solution {
public:
    int trap(vector<int>& height) {
        // brute -> prefix sum and suffix sum tc-o(2n) sc-o(2n)
        /*int n = height.size();
        vector<int> right(n,-1);
        vector<int> left(n,-1);
        int maxi1 = INT_MIN,maxi2 = INT_MIN,ans=0;
        for(int i=0;i<n;i++)
        {
            maxi1 = max(maxi1,height[i]);
            right[i]=maxi1;
            maxi2 = max(maxi2,height[n-1-i]);
            left[n-1-i] = maxi2;
        }
        for(int i=0;i<n;i++)
        {
            int mini = min(right[i],left[i]);
            ans = ans+abs(mini-height[i]);
        }
        return ans;*/

        // better -> suffix sum tc-o(2n) sc-o(n)
        /*int n = height.size();
        vector<int> left(n,-1);
        int maxi = INT_MIN,maxi2 = INT_MIN,ans=0;
        for(int i=0;i<n;i++)
        {
            maxi2 = max(maxi2,height[n-1-i]);
            left[n-1-i] = maxi2;
        }
        for(int i=0;i<n;i++)
        {
            maxi = max(maxi,height[i]);
            int mini = min(maxi,left[i]);
            ans = ans+abs(mini-height[i]);
        }
        return ans;*/

        // optimal -> two pointers tc-o(n) sc-o(1)
        int n = height.size();
        int low = 0,high = n-1,lm=0,rm=0,ans=0;
        while(low<high)
        {
            if(height[low]<=height[high])
            {
                if(lm>height[low])
                    ans = ans + lm-height[low];
                lm = max(lm,height[low]);
                low++;
            }
            else{
                if(rm>height[high])
                    ans = ans + rm-height[high];
                rm = max(rm,height[high]);
                high--;
            }
        }
        return ans;
    }
};