// move zeroes to the end of the array leetcode-283
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // brute
        /* int n=nums.size();
        int count=0;
        for(int i=0;i<n-count;i++)
        {
            if(nums[i]==0)
            {
                count++;
                for(int j=i;j+1<n;j++)
                {
                    swap(nums[j],nums[j+1]);
                }
            }
            if(nums[i]==0)
            i--;
        } */

        // optimal - > two pointers

        int n=nums.size();
        int i=0,j=0;
        while(i<n && j<n)
        {
            while(i<n && nums[i]!=0)
                i++;
            while(j<n && nums[j]==0)
                j++;
            if(i<n && j<n && i<=j)
                swap(nums[i],nums[j]);
            j++;
        }
    }
};