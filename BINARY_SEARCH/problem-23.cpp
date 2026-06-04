// allocate minimum pages - GFG
// book allocation problem
class Solution {
  public:
    int check(vector<int> &nums, int m,int x)
    {
        int n=nums.size(),sum = 0,stu=0;
        for(int i=0;i<n;i++)
        {
            sum = sum + nums[i];
            if(sum == x)
            {
                stu++;
                sum = 0;
            }
            else if(sum>x)
            {
                stu++;
                sum = nums[i];
            }
        }
        if(sum>0)
            stu++;
        if(stu<=m)
            return 1;
        return 0;
    }
    int findPages(vector<int> &nums, int m) {
        // brute -> linear iteration
        /*int n = nums.size();
        if(m>n)
            return -1;
        int mini = *max_element(nums.begin(),nums.end());
        int maxi = accumulate(nums.begin(),nums.end(),0);
        for(int i=mini;i<=maxi;i++)
        {
            if(check(nums,m,i)==1)
                return i;
        }
        return -1;*/
        
        // optimal -> binary search on answers max(min)
        int n = nums.size();
        if(m>n)
            return -1;
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(check(nums,m,mid)==1)
                high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};