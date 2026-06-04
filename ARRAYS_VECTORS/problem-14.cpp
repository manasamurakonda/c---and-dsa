// majority element leetcode - 169
// boyer-moore majority voting algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // brute -> nested loops
        /*int n = nums.size();
        int count = 0;
        for(int i=0;i<n;i++)
        {
            count = 0;
            for(int j = i;j<n;j++)
            {
                if(nums[j] == nums[i])
                    count++;
                if(count>n/2)
                    return nums[i];
            }
        }
        return -1;*/

        // better -> hashing
        /*int n = nums.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
            if(m[nums[i]]>n/2)
                return nums[i];
        }
        return -1;*/
        

        // optimal -> moore's voting algorithm
        // Great explanation of Moore's Voting Algo, very intuitive. Intuition: when there is a majority element its count will not be cancelled out.
        int n = nums.size();
        int count = 0,ans = -1;
        for(int i=0;i<n;i++)
        {
            if(count==0)
                ans = nums[i];
            if(nums[i]==ans)
                count++;
            else count--;
        }
        return ans;
    }
};