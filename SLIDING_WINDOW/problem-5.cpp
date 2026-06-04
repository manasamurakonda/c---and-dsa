// tuf - longest substring with atmost k distinct characters
// leetcode-340(locked)
class Solution {
public:
    int kDistinctChar(string& s, int k) {
        //brute ->generating all substrings
        /*int n = s.size(),ans =0;
        for(int i=0;i<n;i++)
        {
            set <char> st;
            for(int j=i;j<n;j++)
            {
                st.insert(s[j]);
                if(st.size()>k)
                    break;
                ans = max(ans,j-i+1);
            }
        }
        return ans;*/
        // better -> sliding window(pattern 2)
        /*int n = s.size(),ans=0;
        int l=0,r=0;
        map<char,int> m;
        while(r<n)
        {
            m[s[r]]++;
            while(m.size()>k)
            {
                m[s[l]]--;
                if(m[s[l]]==0)
                    m.erase(s[l]);
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;*/

        //optimal -> sliding window(pattern 2 optimized)
        int n = s.size(),ans=0;
        int l=0,r=0;
        map<char,int> m;
        while(r<n)
        {
            m[s[r]]++;
            if(m.size()>k)
            {
                m[s[l]]--;
                if(m[s[l]]==0)
                    m.erase(s[l]);
                l++;
            }
            else
                ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};