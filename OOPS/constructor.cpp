#include<bits/stdc++.h>
using namespace std;
class Teacher{
private:
    double salary;
public:
    string name;
    string subject;
    string dept;

    // constructor overloading

    // non-parameterized constructor
    Teacher()
    {
        cout << "hey i am a non-parameterized constructor" << endl;
    }

    // parameterized constructor
    Teacher(string n,string s,string d,double sal)
    {
        name = n;
        subject = s;
        dept = d;
        salary = sal;
        cout << "hey i am a parameterized constructor" <<endl;
    }

    // copy constructor
    Teacher(Teacher &obj)
    {
        name = obj.name;
        subject = obj.subject;
        dept = obj.dept;
        salary = obj.salary;
        cout << "hey i am a copy constructor" << endl;
    }

    void info()
    {
        cout << name << endl;
        cout << subject << endl;
        cout << dept << endl;
        cout << salary << endl;
    }

};
int main()
{
    Teacher t1("manasa","c++","csm",2500000);
    t1.info();
    Teacher t2;
    Teacher t3(t1);
    t3.info();
    return 0;
}