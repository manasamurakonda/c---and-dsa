#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    for(int i : vec)
    {
        cout<< i << " ";
    }
    cout << endl;
    vector<int>:: iterator it;
    for(auto it = vec.begin() ; it != vec.end() ; it++)
    {
        cout << *(it) << " ";
    }
    cout << endl;
    for(auto it = vec.rbegin() ; it != vec.rend() ; it++)
    {
        cout << *(it) << " ";
    }
    cout << endl;
    return 0;
}