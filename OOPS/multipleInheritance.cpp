#include<iostream>
using namespace std;


class Student{
public: 
    string name;
    int rollno;
};

class Teacher{
public:
    string subject;
    double salary;
};

class TA : public Student, public Teacher{

};
int main()
{
    TA t1;
    t1.name = "manasa";
    t1.rollno = 1;
    t1.subject = "AI & ML";
    t1.salary = 2500000;
    cout << t1.name << endl;
    cout << t1.rollno << endl;
    cout << t1.subject << endl;
    cout << t1.salary << endl;
    return 0;
}