#include<bits/stdc++.h>
using namespace std;
class Person{
public:
    string name;
    int age;

    Person()
    {
        cout << "hey i am Person class constructor" << endl;
    }
};

class Student : public Person{
public:
    int rollno;

    Student(){
        cout << "hey i am Student class constructor" << endl;
    }
};
int main()
{
    Student s1;
    return 0;
}