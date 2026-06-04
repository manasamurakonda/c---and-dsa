// lemonade change
// leetcode - 860

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // optimal -> greedy in spending 5 rupee coins tc-o(n) sc-o(1)
        int tens=0,fives=0;
        int n = bills.size();
        for(int i=0;i<n;i++)
        {
            if(bills[i]==20)
            {
                if(tens>=1 && fives>=1)
                {
                    tens--;
                    fives--;
                }
                else if(fives>=3)
                {
                    fives = fives-3;
                }
                else return false;
            }
            else if(bills[i]==10)
            {
                if(fives>=1)
                {
                    fives--;
                    tens++;
                }
                else return false;
            }
            else fives++;
        }
        return true;
    }
};