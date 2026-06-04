#include<bits/stdc++.h>
using namespace std;
class Teacher{
public:
    // properties // attributes
    string name;
    string dept;
    string subject;
    double salary;
    // methods // member functions
    void changeDept(string dep)
    {
        dept = dep;
        cout << "department changed successfully" << endl;
    }
};
int main()
{
    Teacher t1;
    t1.name = "manasa";
    t1.dept = "cse";
    t1.subject = "c++";
    t1.salary = 25000;
    cout << t1.name << endl;
    cout << t1.dept << endl;
    cout << t1.subject << endl;
    cout << t1.salary << endl;
    t1.changeDept("csm");
    cout << t1.dept << endl;
    return 0;
}