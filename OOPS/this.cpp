#include<bits/stdc++.h>
using namespace std;
class Teacher{
private:
    double salary;
public:
    string name;
    string subject;
    string dept;
    Teacher(string name,string subject,string dept,double salary)
    {
        // this pointer
        this->name = name;
        this->subject = subject;
        this->dept = dept;
        this->salary = salary;
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
    return 0;
}