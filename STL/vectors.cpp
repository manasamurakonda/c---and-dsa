#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    for(int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    v.pop_back();
    v.emplace_back(5);
    cout<< v.size() << " " << v.capacity() << endl;
    v[6] = 6;
    cout << v[6] << endl;
    cout << v.at(0) << endl;
    v.push_back(6);
    cout << v.front() << endl;
    cout << v.back() << endl;
    v.erase(v.begin());
    v.erase(v.begin(),v.begin()+2);
    //v.clear();
    for(int i : v)
    {
        cout << i << " ";
    }
    cout<< endl;
    v.erase(v.begin());
    cout<< v.empty() << endl;
    v.insert(v.begin(),1);
    v.insert(v.begin()+1,2);
    v.insert(v.begin()+2,3);
    for(int i : v)
    {
        cout << i << " ";
    }
    return 0;
}