#include<bits/stdc++.h>
using namespace std;
class Person{
public:
    string name;
    int age;

    Person(){

    }
};

class Student : public Person{
public:
    int rollno;

    void getInfo(){
        cout << name << endl;
        cout << age << endl;
        cout << rollno << endl;
    }
};
int main()
{
    Student s1;
    s1.name = "manasa";
    s1.age = 20;
    s1.rollno = 1;
    s1.getInfo();
    return 0;
}