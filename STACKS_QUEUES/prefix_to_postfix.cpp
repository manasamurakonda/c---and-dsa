#include<bits/stdc++.h>
using namespace std;

bool isOperand(char ch)
{
    if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'))
        return true;
    return false;
}

int main()
{
    string postfix;
    cout<<"enter prefix expression: ";
    cin>>postfix;
    int n = postfix.size();
    stack<string> st;
    for(int i=n-1;i>=0;i--)
    {
        string ch = "";
        ch = ch+postfix[i];
        if(isOperand(postfix[i]))
            st.push(ch);
        else{
            string a = st.top();
            st.pop();
            string b = st.top();
            st.pop();
            string temp = a+b+ch;
            st.push(temp);
        }
    }
    cout<<"the postfix expression is: ";
    cout<<st.top()<<endl;
    return 0;
}