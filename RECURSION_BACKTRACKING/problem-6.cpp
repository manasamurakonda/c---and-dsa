// sum of first n natural numbers using recursion
#include<bits/stdc++.h>
using namespace std;


int fun(int i,int n)
{
    if(i==n+1)
        return 0;
    return i+fun(i+1,n);
}
int main()
{
    int n;
    cout<<"enter n: ";
    cin>>n;
    cout<<"sum of first "<<n<<" natural numbers is: "<<fun(1,n);
    return 0;
}