#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=101;
    int ans=0,two=1;
    while(n>0)
    {
        if(n%10==1)
        {
            ans=ans+two;
        }
        two=two*2;
        n=n/10;
    }
    cout<<ans;
}