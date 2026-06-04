#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter n: ";
    cin>>n;
    if((n&(n-1))==0){
        cout<<"power of 2 ";
    }
    else
        cout<<"not power of 2";
    return 0;
}