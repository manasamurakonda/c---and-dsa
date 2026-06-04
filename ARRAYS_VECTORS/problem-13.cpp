// sort an array of 0's , 1's and 2's
// leetcode - 75 sort colors
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // brute -> sorting
        //sort(nums.begin(),nums.end());

        // better -> kind of counting
        /*int n = nums.size(),z=0,o=0,t=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
                z++;
            if(nums[i]==1)
                o++;
            if(nums[i]==2)
                t++;
        }
        int x =0;
        while(z>0)
        {
            nums[x]=0;
            z--;
            x++;
        }
        while(o>0)
        {
            nums[x]=1;
            o--;
            x++;
        }
        while(t>0)
        {
            nums[x]=2;
            t--;
            x++;
        }*/


        // optimal -> three pointer approach -> dutch national flag algorithm
        int n=nums.size();
        int low = 0, mid = 0, high = n-1;
        while(mid <= high)
        {
            if(nums[mid] == 0)
            {
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 2)
            {
                swap(nums[high],nums[mid]);
                high--;
            }
            else
                mid++;
        }
    }
};