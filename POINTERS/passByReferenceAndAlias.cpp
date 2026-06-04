// pass by reference
/* #include<bits/stdc++.h>
using namespace std;
void changeA(int *b)
{
    *b=100;
}
int main()
{
    int a;
    a=5;
    cout << a << endl;
    changeA(&a);
    cout << a;
    return 0;
} */

// pass by reference using alias
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void changeA(int &b)
{
    b=100;
}
int main()
{
    int a;
    a=5;
    cout << a << endl;
    changeA(a);
    cout << a;
    return 0;
}