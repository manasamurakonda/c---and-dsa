#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a=5;
    int *ptr = &a;
    cout << ptr << endl;
    cout << ptr++ << endl;
    cout << ptr << endl;
    ptr = ptr + 1;
    cout << ptr << endl;
    ptr = ptr - 1;
    cout << ptr << endl;
    int *ptr1 = ptr +2;
    cout << (ptr > ptr1) << endl;
    cout << (ptr < ptr1) << endl;
    cout << (ptr >= ptr1) << endl;
    cout << (ptr <= ptr1) << endl;
    cout << (ptr == ptr1) << endl;
    cout << (ptr != ptr1) << endl;
    return 0;
}