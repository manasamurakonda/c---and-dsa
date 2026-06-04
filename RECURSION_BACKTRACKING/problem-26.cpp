// kth permutation sequence
// leetcode - 60
class Solution {
public:
    void compute(vector<char> &nums,int n,vector<string> &ans,vector<int> &flag,string &temp)
    {
        if(temp.size()==n)
        {
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<n;i++)
        {
            if(flag[i]==0)
            {
                flag[i]=1;
                temp.push_back(nums[i]);
                compute(nums,n,ans,flag,temp);
                temp.pop_back();
                flag[i]=0;
            }
        }
    }
    void compute1(int ind,string &nums,int n,vector<string> &ans)
    {
        if(ind == n){
            ans.push_back(nums);
            return;
        }
        
        for(int i=ind;i<n;i++)
        {
            swap(nums[ind],nums[i]);
            compute1(ind+1,nums,n,ans);
            swap(nums[ind],nums[i]);
        }
    }
    string getPermutation(int n, int k) {
        // brute -> generate all permutations using recursion and  flag array
        /*vector<char> nums;
        for(int i=1;i<=n;i++)
            nums.push_back(i+'0');
        vector<string> ans;
        vector<int> flag(n,0);
        string temp = "";
        compute(nums,n,ans,flag,temp);
        return ans[k-1];*/

        // tle due to sorting
        /*string nums = "";
        for(int i=1;i<=n;i++)
            nums.push_back(i+'0');
        vector<string> ans;
        compute1(0,nums,n,ans);
        sort(ans.begin(),ans.end());
        return ans[k-1];*/

        // optimal -> using math and recursion (pending)
    }
};