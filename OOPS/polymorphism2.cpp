#include<iostream>
using namespace std;
class Complex{
public:
    int real;
    int imaginary;
    Complex(int r, int i)
    {
        real = r;
        imaginary = i;
    }
    void show()
    {
        cout << real << "+" << imaginary << "i" << endl;
    }
    Complex operator +(Complex c)
    {
        Complex answer(0,0);
        answer.real = real + c.real;
        answer.imaginary = imaginary + c.imaginary;
        return answer;
    }
};
int main()
{
    Complex c1(1,2);
    c1.show();
    Complex c2(3,4);
    c2.show();
    // observe this line...why cant i just write Complex c3;
    Complex c3(0,0);
    c3 = c1 + c2;
    c3.show();
    return 0;
}