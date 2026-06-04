#include<bits/stdc++.h>
using namespace std;
class Print{
public:
    // you already saw constructor overloading
    void show(int x)
    {
        cout << x << endl;
    }
    void show(string x)
    {
        cout << x << endl;
    }
};
int main()
{
    Print p;
    p.show(100);
    p.show("manasa murakonda");
    return 0;
}