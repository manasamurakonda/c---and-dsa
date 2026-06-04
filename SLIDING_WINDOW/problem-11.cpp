// minimum window substring
// leetcode-76
class Solution {
public:
    string minWindow(string s, string t) {
        // brute -> generating all subarrays
        /*int n = s.size(),len=INT_MAX,si=-1;
        int n1=t.size();
        string ans = "";
        for(int i=0;i<n;i++)
        {
            unordered_map<char,int> m;
            int count=0;
            for(int j=0;j<n1;j++)
            {
                m[t[j]]++;
            }
            for(int j=i;j<n;j++)
            {
                if(m.find(s[j])!=m.end() && m[s[j]]>0)
                    count++;
                m[s[j]]--;
                if(count==n1)
                {
                    if(len>j-i+1)
                    {
                        len=j-i+1;
                        si = i;
                    }
                    break;
                }
            }
            if(si!=-1)
                ans = s.substr(si,len);
        }
        return ans;*/

        // optimal ->slidng window(pattern -4)
        int n=s.size(),n1=t.size();
        int len=INT_MAX,si=-1;
        string ans="";
        int l=0,r=0,count=0;
        unordered_map<char,int> m;
        for(int i=0;i<n1;i++)
        {
            m[t[i]]++;
        }
        while(r<n)
        {
            if(m.find(s[r])!=m.end() && m[s[r]]>0)
                count++;
            m[s[r]]--;
            if(count==n1)
            {
                while(count==n1)
                {
                    if(len>r-l+1)
                    {
                        len = r-l+1;
                        si = l;
                    }
                    m[s[l]]++;
                    if(m[s[l]]>0){
                        count--;
                    }
                    l++;
                }
            }
            r++;
        }
        if(si!=-1)
            ans = s.substr(si,len);
        return ans;
    }
};