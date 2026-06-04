// longest consecutive sequence leetcode - 128
class Solution {
public:
    bool linear_search(int x,vector<int> &nums)
    {
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==x)
                return true;
        }
        return false;
    }
    int longestConsecutive(vector<int>& nums) {
        // brute
        /*int n = nums.size();
        int ans = 0,count=1;
        for(int i=0;i<n;i++)
        {
            int x = nums[i];
            count = 1;
            while(linear_search(x+1,nums))
            {
                x=x+1;
                count++;
            }
            ans = max(ans,count);
        }
        return ans;*/
        // better -> sorting
        /*int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = 0,count = 1;
        if(n==0)
            return 0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]==(nums[i-1]+1))
                count++;
            else if(nums[i]==nums[i-1])
                continue;
            else{
                ans = max(ans, count);
                count = 1;
            }
            ans = max(ans,count);
        }
        ans = max(ans,count);
        return ans;*/

        // optimal ->hashing or you can use set as well
        int n = nums.size();
        int ans = 0,count = 1;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
        }
        for(auto it : m)
        {
            int x = it.first;
            count = 1;
            if(m.find(x-1)==m.end())
            {
                while(m.find(x+1)!=m.end())
                {
                    x++;
                    count++;
                }
            }
            ans = max(ans,count);
        }
        return ans;
    }
};