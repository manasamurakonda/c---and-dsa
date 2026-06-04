// reverse pairs
// leetcode - 493
class Solution {
public:
    int revPairs(vector<int> &nums,int left,int mid,int right)
    {
        int j=mid+1,count=0;
        for(int i=left;i<=mid;i++)
        {
            while(j<=right && (long long)nums[i]>2LL*(long long)nums[j])
                j++;
            count = count + (j-(mid+1));
        }
        return count;
    }
    void merge(vector<int> &nums,int left,int mid,int right)
    {
        int i = left,j=mid+1;
        vector<int> temp;
        while(i<=mid && j<=right)
        {
            if(nums[i]<=nums[j])
            {
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid)
        {
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=right)
        {
            temp.push_back(nums[j]);
            j++;
        }
        for(int i=left;i<=right;i++)
        {
            nums[i] = temp[i-left];
        }
    }
    int mergeSort(vector<int> &nums,int left,int right)
    {
        int count = 0;
        if(left<right)
        {
            int mid = (left+right)/2;
            count += mergeSort(nums,left,mid);
            count += mergeSort(nums,mid+1,right);
            count += revPairs(nums,left,mid,right);
            merge(nums,left,mid,right); 
        }
        return count;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums,0,n-1);
    }
};