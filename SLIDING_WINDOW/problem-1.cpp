// maximum points you can obtain from cards
// leetcode -1423
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // my logic(not so much good)
        /*int l=0,r=0;
        int n = cardPoints.size(),sum=0,ans=0;
        while(r<k)
        {
            sum=sum+cardPoints[r];
            r++;
        }
        r--;
        ans=max(ans,sum);
        l=n-1;
        while(r>=0 && l>=0)
        {
            sum=sum+cardPoints[l--];
            sum=sum-cardPoints[r--];
            ans=max(ans,sum);
        }
        return ans;*/
        // n-k subarray ni theeseskuntu pothey chalu kadha
        int n= cardPoints.size();
        int total = 0,ans=0;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(i==n-k)
                sum = total;
            total = total + cardPoints[i];
        }
        ans = max(ans,total-sum);
        int l=0,r=n-k;
        while(r<n)
        {
            sum = sum+cardPoints[r++];
            sum = sum-cardPoints[l++];
            ans = max(ans,total-sum);
        }
        return ans;
    }
};