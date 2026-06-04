#include<iostream>
using namespace std;
#include<map>
int main()
{
    map<string,int> m;
    m["manasa"]=100;
    m["navya"]=100;
    m["asritha"]=89;
    m["nandini"]=70;
    m["sampath"]=89;
    for(auto it : m)
    {
        cout << it.first << " " << it.second <<endl;
    }
    m.insert({"deepanjali",60});
    cout << m["deepanjali"] << endl;
    m.erase("deepanjali");
    m.insert({"deepanjali",60});
    //m["deepanjali"]=60;
    for(auto it : m)
    {
        cout << it.first << " " << it.second <<endl;
    }
    return 0;
}