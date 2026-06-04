// count all subsequences with sum k
// recursion - take and not take concept
// tc- o(2^n) sc-o(n)
class Solution{
    public:
    void compute(int ind,int n,vector<int> &nums,int k,int &count,int sum)
    {
        if(ind>=n)
        {
            if(sum==k)
                count++;
            return;
        }

        sum = sum + nums[ind];
        compute(ind+1,n,nums,k,count,sum);
        sum = sum - nums[ind];
        compute(ind+1,n,nums,k,count,sum);
    }
    int countSubsequenceWithTargetSum(vector<int>& nums, int k){
    	int n = nums.size(),count=0;
        compute(0,n,nums,k,count,0);
        return count;
    }
};