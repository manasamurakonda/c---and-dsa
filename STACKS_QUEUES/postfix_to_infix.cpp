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
    cout<<"enter postfix expression: ";;
    cin>>postfix;
    stack<string> st;
    int n = postfix.size();
    for(int i=0;i<n;i++)
    {
        string ch = "";
        ch = ch+postfix[i];
        if(isOperand(postfix[i]))
            st.push(ch);
        else{
            string b = st.top();
            st.pop();
            string a = st.top();
            st.pop();
            string temp = "("+a+ch+b+")";
            st.push(temp);
        }
    }
    cout<<"the infix of given postfix is: ";
    cout<<st.top()<<endl;
    return 0;
}