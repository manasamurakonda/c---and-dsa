// fruit into baskets
// leetcode - 904
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // brute -> generating all subarrays(can also use set data structure)
        /*int n=fruits.size();
        int ans =0,first=-1,second=-1;
        for(int i=0;i<n;i++)
        {
            first = -1,second = -1;
            for(int j=i;j<n;j++)
            {
                if(first == -1)
                {
                    first = fruits[j];
                }
                else if(second ==-1 && fruits[j]!=first)
                {
                    second = fruits[j];
                }
                else if(fruits[j]!=first && fruits[j]!=second)
                {
                    ans = max(ans,j-i);
                    break;
                }
                if(j==n-1)
                    ans = max(ans,j-i+1);
            }
        }
        return ans;*/

        // better -> sliding window(pattern 2)
        /*int n = fruits.size(),ans = 0;
        int l=0,r=0;
        map<int,int> m;
        while(r<n)
        {
            m[fruits[r]]++;
            if(m.size()>2)
            {
                while(m.size()>2)
                {
                    m[fruits[l]]--;
                    if(m[fruits[l]]==0)
                    {
                        m.erase(fruits[l]);
                    }
                    l++;
                }
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;*/
        // optimal -> (sliding window -> pattern 2 optimized)
        int n = fruits.size(),ans = 0;
        int l=0,r=0;
        map<int,int> m;
        while(r<n)
        {
            m[fruits[r]]++;
            if(m.size()>2)
            {
                m[fruits[l]]--;
                if(m[fruits[l]]==0)
                {
                    m.erase(fruits[l]);
                }
                l++;
            }
            else
                ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};