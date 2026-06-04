// intersection of two sorted arrays
// two pointers vadali
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> first = {1,2,3,4,7};
    vector<int> second = {1, 2, 3, 4, 6, 7};
    vector<int> ans;
    int i = 0, j = 0;
    while(i < first.size() && j < second.size())
    {
        if(ans.empty() || ans.back()!=first[i])
        {
            if(first[i] == second[j]){
                ans.push_back(first[i]);
                i++;            
            }
            else if(first[i] > second[j])
                j++;
            else
                i++;
        }
        else
            i++;
    }
    for(auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
}