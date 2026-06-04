// print linearly from 1 to n using backtracking
#include<bits/stdc++.h>
using namespace std;


void display(int n)
{
    if(n==0)
        return;
    display(n-1);
    cout<<n<<" ";
}
int main()
{
    int n;
    cout<<"enter n: ";
    cin>>n;
    display(n);
    return 0;
}