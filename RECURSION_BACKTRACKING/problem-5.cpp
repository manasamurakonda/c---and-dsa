// print linearly form n to 1 using backtracking
#include<bits/stdc++.h>
using namespace std;

void display(int i,int n)
{
    if(i==n+1)
        return;
    display(i+1,n);
    cout<<i<<" ";
}
int main()
{
    int n;
    cout<<"enter n: ";
    cin>>n;
    display(1,n);
    return 0;
}