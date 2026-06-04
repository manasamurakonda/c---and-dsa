// sliding window maximum
// leetcode - 239

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // brute -> nested loops tc-o(k*n) sc-o(1)
        /*int n = nums.size();
        vector<int> ans;
        int low = 0,high = k-1;
        while(high<n)+
        {
            int maxi = INT_MIN,i=low;
            while(i<=high)
            {
                maxi = max(maxi,nums[i]);
                i++;
            }
            ans.push_back(maxi);
            low++;
            high++;
        }
        return ans;*/
        // optimal ->using deque tc-o(2n) sc-o(k)
        vector<int> ans;
        int n  = nums.size();
        deque<int> dq;
        for(int i=0;i<n;i++)
        {
            while(!dq.empty() && nums[dq.back()]<=nums[i])
                dq.pop_back();
            dq.push_back(i);
            if(i>=k-1)
            {
                while(dq.front()<i-(k-1))
                    dq.pop_front();
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};