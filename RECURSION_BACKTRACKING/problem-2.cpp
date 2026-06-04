// print linearly from 1 to n
#include<bits/stdc++.h>
using namespace std;

void display(int i,int n)
{
    if(i>n)
        return;
    cout<<i<<" ";
    display(i+1,n);
}
int main()
{
    int n;
    cout<<"enter n: ";
    cin>>n;
    display(1,n);
    return 0;
}