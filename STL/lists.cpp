#include<iostream>
#include<list>
using namespace std;
int main()
{
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    for(auto it : l)
    {
        cout<< it << " ";
    }
    cout << endl;
    l.push_front(0);
    l.push_front(-1);
    l.push_front(-2);
    l.push_front(-3);
    l.push_front(-4);
    for(auto it : l)
    {
        cout<< it << " ";
    }
    cout << endl;
    l.pop_back();
    l.pop_front();
    for(auto it : l)
    {
        cout<< it << " ";
    }
    cout << endl;
    cout << l[0]; // random element access not allowed in lists
    return 0;
}