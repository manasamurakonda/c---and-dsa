#include<bits/stdc++.h>
using namespace std;
class Student{
public:
    string name;
    double* cgpa;
    Student(string name,double gpa)
    {
        this->name = name;
        cgpa = new double;
        *cgpa = gpa;
    }

    // // shallow copy
    // Student(Student &s)
    // {
    //     this->name = s.name;
    //     cgpa = s.cgpa;
    // }

    // deep copy
    Student(Student &s)
    {
        this->name = s.name;
        cgpa = new double;
        *cgpa = *(s.cgpa);
    }
    void getInfo()
    {
        cout << name << endl;
        cout << *cgpa << endl;
    }
};
int main()
{
    Student s1("manasa",9.8);
    s1.getInfo();
    Student s2(s1);
    s2.getInfo();
    *(s2.cgpa) = 9.7;
    s2.name = "navya";
    s2.getInfo();
    s1.getInfo();
    return 0;
}