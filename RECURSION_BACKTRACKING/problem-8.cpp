// reversing an array using recursion
#include<bits/stdc++.h>
using namespace std;


void rev(int arr[],int n,int i)
{
    if(i>=(n/2))
        return;
    int temp = *(arr+i);
    *(arr+i) = *(arr+n-1-i);
    *(arr+n-1-i) = temp;
    rev(arr,n,i+1);
}
int main()
{
    int arr[100],n;
    cout<<"enter array size: ";
    cin>>n;
    cout<<"enter array elements: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    rev(arr,n,0);
    cout<<"reversed array is: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}