#include<iostream>
using namespace std;
#include<set>
int main()
{
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.emplace(0);
    for(auto it : s)
    {
        cout << it << " ";
    }
    s.erase(s.begin());
    cout << endl;
    for(auto it : s)
    {
        cout << it << " ";
    }
    cout << endl;
    cout << s.count(1) << endl;
    cout << *(s.lower_bound(4)) << endl;
    cout << *(s.upper_bound(4)) << endl;
    return 0;
}