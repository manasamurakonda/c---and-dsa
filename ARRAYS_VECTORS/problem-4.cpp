// rotate an array by k places leetcode - 189
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // brute
        /* int n = nums.size();
        while(k>=n)
            k=k-n;
        vector<int> temp;
        int pos = n-k;
        for(int i=pos;i<n;i++)
        {
            temp.push_back(nums[i]);
        }
        int j=n-1;
        for(int i=pos-1;i>=0;i--)
        {
            nums[j]=nums[i];
            j--;
        }
        for(int i=0;i<k;i++)
        {
            nums[i]=temp[i];
        } */

        // optimal 3 reversals vadu
        // .begin(),.end() ekkada point chesthayo thelskoni sav and k>n untey em cheyalo aalochinchu
        int n = nums.size();
        while(k>=n)
            k=k-n;
        reverse(nums.begin(),nums.end()-k);
        reverse(nums.end()-k,nums.end());
        reverse(nums.begin(),nums.end());
    }
};