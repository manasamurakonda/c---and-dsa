// longest substring without repeating characters
// leetcode-3
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // brute -> generating all the subarrays
        // hashmap badhulu hash array vadu hash[256]
        /*int n =s.size();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            unordered_map<char,int> m;
            for(int j=i;j<n;j++)
            {
                if(m.find(s[j])!=m.end())
                {
                    break;
                }
                m[s[j]]=j;
                ans = max(ans,j-i+1);
            }
        }
        return ans;*/
        // optimal->sliding window(pattern 2)
        int n = s.size();
        unordered_map<char,int> m;
        int l=0,r=0,ans=0;
        while(r<n)
        {
            if(m.find(s[r])!=m.end() && m[s[r]]>=l)
            {
                l=m[s[r]]+1;
            }
            m[s[r]]=r;
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};