// longest repeating character replacement
// leetcode -424
class Solution {
public:
    int characterReplacement(string s, int k) {
        // brute-> generating all substrings
        /*int n=s.size(),ans=0,maxf=0;
        for(int i=0;i<n;i++)
        {
            maxf=0;
            unordered_map<int,int> m;
            for(int j=i;j<n;j++)
            {
                m[s[j]]++;
                maxf = max(maxf,m[s[j]]);
                if(((j-i+1)-maxf)>k)
                {
                    break;
                }
                ans=max(ans,j-i+1);
            }
        }
        return ans;*/
        // better-> sliding window (pattern 2)
        /*int n = s.size(),ans=0,maxf=0;
        int l=0,r=0;
        unordered_map<char,int> m;
        while(r<n)
        {
            m[s[r]]++;
            if(maxf<=m[s[r]])
            {
                maxf=m[s[r]];
            }
            while((r-l+1)-maxf>k)
            {
                m[s[l]]--;
                for(auto it : m)
                {
                    maxf=max(maxf,it.second);
                }
                l++;
            }
            if((r-l+1)-maxf<=k)
                ans=max(ans,r-l+1);
            r++;
        }
        return ans;*/
        // optimal -> sliding window (pattern 2 optimized)
        int n = s.size(),ans=0,maxf=0;
        int l=0,r=0;
        unordered_map<char,int> m;
        while(r<n)
        {
            m[s[r]]++;
            if(maxf<=m[s[r]])
            {
                maxf=m[s[r]];
            }
            if((r-l+1)-maxf>k)
            {
                m[s[l]]--;
                for(auto it : m)
                {
                    maxf=max(maxf,it.second);
                }
                l++;
            }
            if((r-l+1)-maxf<=k)
                ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};