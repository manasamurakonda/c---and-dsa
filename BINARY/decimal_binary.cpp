#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=10;
    int ans=0,pow=1;
    while(n>0)
    {
        ans=ans+(pow*(n%2));
        n=n/2;
        pow=pow*10;
    }
    cout<<ans;
}