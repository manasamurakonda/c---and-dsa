#include<iostream>
using namespace std;
class Person{
public:
    string name;
};

// observe class name
class student : public Person{
public:
    int rollno;
};

class gradStudent : public student{
public:
    string researchArea;
};
int main()
{
    gradStudent s1;
    s1.name = "manasa";
    s1.rollno = 1;
    s1.researchArea = "AI & ML";
    cout << s1.name << endl;
    cout << s1.rollno << endl;
    cout << s1.researchArea << endl;
    return 0;
}