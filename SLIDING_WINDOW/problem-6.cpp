// number of substrings containing all 3 characters
// leetcode-1358
class Solution {
public:
    int numberOfSubstrings(string s) {
        // brute -> generating all substrings
        /*int n=s.size(),ans=0;
        for(int i=0;i<n;i++)
        {
            map<char,int> m;
            for(int j=i;j<n;j++)
            {
                m[s[j]]++;
                if(m.size()==3)
                    ans++;
            }
        }
        return ans;*/
        //optimal-> think about...no.of substrings that end with ith character
        /*int n = s.size(),ans=0;
        map<char,int> m;
        m['a']=-1;
        m['b']=-1;
        m['c']=-1;
        for(int i=0;i<n;i++)
        {
            m[s[i]]=i;
            if(m['a']!=-1 && m['b']!=-1 && m['c']!=-1)
            {
                int x = min(m['a'],m['b']);
                x=min(x,m['c']);
                ans = ans + x+1;
            }
        }
        return ans;*/
        // better - > (sliding window pattern 3)(no.of substrings having <=3 characters - <=2 characters)
        long long n = s.size(),y=0;
        long long l=0,r=0;
        long long x=(n*(n+1))/2;
        unordered_map<char,int> m;
        while(r<n)
        {
            m[s[r]]++;
            while(m.size()>2)
            {
                m[s[l]]--;
                if(m[s[l]]==0)
                    m.erase(s[l]);
                l++;
            }
            y=y+(r-l+1);
            r++;
        }
        return x-y;
    }
};