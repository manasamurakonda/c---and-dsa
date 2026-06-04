#include<bits/stdc++.h>
using namespace std;
// this is also an example for encapsulation
class Teacher{
    private:
        double salary;
    public:
        string name;
        string dept;
        string subject;

        void setSalary(double sal)
        {
            salary = sal;
        }
        double getSalary()
        {
            return salary;
        }
};
int main()
{
    Teacher t1;
    t1.name = "manasa";
    t1.dept = "cse";
    t1.subject = "c++";
    t1.setSalary(1000000);
    cout << t1.name << endl;
    cout << t1.dept << endl;
    cout << t1.subject << endl;
    cout << t1.getSalary() << endl;
    return 0;
}