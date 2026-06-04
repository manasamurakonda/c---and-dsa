#include<iostream>
#include<deque>
using namespace std;
int main()
{
    deque<int> d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_back(4);
    d.push_back(5);
    for(auto it : d)
    {
        cout<< it << " ";
    }
    cout << endl;
    d.push_front(0);
    d.push_front(-1);
    d.push_front(-2);
    d.push_front(-3);
    d.push_front(-4);
    for(auto it : d)
    {
        cout<< it << " ";
    }
    cout << endl;
    d.pop_back();
    d.pop_front();
    for(auto it : d)
    {
        cout<< it << " ";
    }
    cout << endl;
    cout << d[0]; // random element access is allowed in deque
    return 0;
}