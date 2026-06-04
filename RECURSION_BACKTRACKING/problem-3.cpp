// print linearly from n to 1
#include<bits/stdc++.h>
using namespace std;


void display(int n)
{
    if(n==0)
        return;
    cout<<n<<" ";
    display(n-1);
}
int main()
{
    int n;
    cout<<"enter n: ";
    cin>>n;
    display(n);
    return 0;
}