// union of two sorted arrays
// use a pointer for one array and another pointer for another array
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> first = {1, 2, 3, 3, 4, 5};
    vector<int> second = {1, 1, 3, 4, 6, 7};
    vector<int> ans;
    int i = 0, j = 0;
    while(i < first.size() && j < second.size())
    {
        if(first[i]<=second[j])
        {
            if(ans.empty() || first[i]!=ans.back())
                ans.push_back(first[i]);
            i++;
        }
        else{
            if(ans.empty() || second[j]!=ans.back())
                ans.push_back(second[j]);
            j++;
        }
    }
    while(i < first.size())
    {
        if(ans.empty() || first[i]!=ans.back())
                ans.push_back(first[i]);
            i++;
    }
    while(j < second.size())
    {
        if(ans.empty() || second[j]!=ans.back())
                ans.push_back(second[j]);
            j++;
    }
    for(int val : ans){
        cout << val << " ";
    }
}