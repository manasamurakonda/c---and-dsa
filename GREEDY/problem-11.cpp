class Solution {
public:
    bool checkValidString(string s) {
        // brute -> recursion (pending)

        // better -> using two stacks (pending)

        // optimal -> greedy(maintaining range) tc-o(n) sc-o(1)
        int n = s.size(),maxi=0,mini=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                mini++;
                maxi++;
            }
            else if(s[i]==')'){
                mini--;
                maxi--;
            }
            else{
                mini--;
                maxi++;
            }
            if(maxi<0)
                return false;
            if(mini<0)
                mini=0;
        }
        return mini==0;
    }
};