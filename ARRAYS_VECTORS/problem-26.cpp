// missing and repeating gfg
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // brute
        /*int mis=-1,reap = -1;
        int n = arr.size(),flag =0,cnt =0;
        for(int i=1;i<n;i++)
        {
            cnt =0;
            for(int j=0;j<n;j++)
            {
                if(i==arr[j])
                {
                    cnt++;
                    if(cnt ==2)
                        reap = i;
                }
                if(j==n-1 && cnt ==0)
                    mis = i;
            }
            if(mis !=-1 && reap!=-1)
                return {reap,mis};
        }*/
        
        // better -> hashing(hash array is fine)
        /*vector<int> ans;
        int n = arr.size();
        vector<int> hash(n+1,0);
        for(int i=0;i<n;i++)
        {
            hash[arr[i]]=hash[arr[i]]+1;
            if(hash[arr[i]]==2)
                ans.push_back(arr[i]);
        }
        for(int i=1;i<=n;i++)
        {
            if(hash[i]==0)
            {
                ans.push_back(i);
                break;
            }
        }
        return ans;*/
        // optimal-1 -> math(anni variables long long lo theesko)
        long long n =arr.size();
        long long x,y,xmy,xpy;
        long long s1=0,s1n,s2 = 0,s2n;
        for(int i=0;i<n;i++)
        {
            s1=s1+arr[i];
            s2 = s2 + ((long long)arr[i] * (long long)arr[i]);
        }
        s1n = (n*(n+1))/(long long)2;
        xmy = (s1-s1n);
        s2n = (n*(n+1)*(2*n+1))/(long long)6;
        xpy = (s2-s2n)/xmy;
        x = (xmy+xpy)/(long long)2;
        y = (xpy-xmy)/(long long)2;
        return {(int)x,(int)y};
        
        // optimal-2 bit manipulation - > (optional)
    }
};