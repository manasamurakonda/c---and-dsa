// print name 5 times
#include<bits/stdc++.h>
using namespace std;
void name(int n)
{
    if(n==0)
        return;
    cout<<"manasa"<<endl;
    name(n-1);
}
int main()
{
    int n;
    cout<<"enter n: ";
    cin>>n;
    name(n);
    return 0;
}