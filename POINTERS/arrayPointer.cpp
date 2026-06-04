#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = { 1, 2, 3, 4, 5};
    cout << arr << endl;
    cout << *(arr) << endl;
    cout << *(arr+1) << endl;
    // trying to reassign arr pointer to another array
    int b[] = {1, 2, 3, 4, 6};
    arr = b; // throws error as array pointer is constant pointer
    cout << arr;
    return 0;
}