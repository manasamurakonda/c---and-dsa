// maximum product subarray leetcode-152
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // brute - > nested loops
        /*int prod=1,maxi = INT_MIN,n=nums.size();
        for(int i=0;i<n;i++)
        {
            prod = 1;
            for(int j=i;j<n;j++)
            {
                prod = prod*nums[j];
                maxi = max(maxi,prod);
            }
        }
        return maxi;*/

        //optimal -1 -> observation bases(prefix product and suffix product)
        int n = nums.size(),prf =1,suf=1,maxi = INT_MIN;
        for(int i=0;i<n;i++)
        {
            prf = prf*nums[i];
            maxi = max(maxi,prf);
            if(prf == 0)
                prf =1;
            suf = suf*nums[n-1-i];
            maxi = max(maxi,suf);
            if(suf == 0)
                suf =1;
        }
        return maxi;

        // optimal-2 ->modification of kadanes algorithm(pending)(not good to say this approach to interviewer...endhukantey it is not that intutive)
    }
};