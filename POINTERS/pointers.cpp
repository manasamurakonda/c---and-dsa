#include<bits/stdc++.h>
using namespace std;
int main(){
    int a=10;
    cout<< a <<endl;
    cout<< &a<<endl;
    //pointer
    int *ptr = &a;
    cout<<ptr<<endl;
    cout<< *ptr;
    cout<< &ptr;
    // pointer to pointer
    int** ptr1= &ptr;
    cout << ptr1 << endl;
    cout << *ptr1 << endl;
    cout << **ptr1 << endl;
    cout << *(&a) << endl;
    // null pointer
    int *ptr2=NULL;
    cout << ptr2;
    // not possible...segmentation fault
    cout << *ptr2;
    return 0;
}