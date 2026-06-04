#include<iostream>
using namespace std;
class Parent{
public:
    // virtual function example
    virtual void show()
    {
        cout << "hey i am show method in Parent class" << endl;
    }
};
class Child : public Parent{
public:
    void show()
    {
        cout << "hey i am show method in Child class" << endl;
    }
};
int main()
{
    Child c;
    c.show();
    return 0;
}