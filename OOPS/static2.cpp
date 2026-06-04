#include<iostream>
using namespace std;
class A{
public:
    A(){
        cout << "constructor" << endl;
    }
    ~A(){
        cout << "destructor" << endl;
    }
};

int main()
{
    if(1){
        static A a;
    }
    cout <<"end of the program" << endl;
    return 0;
}