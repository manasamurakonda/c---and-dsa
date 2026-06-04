#include<bits/stdc++.h>
using namespace std;
bool isOperator(char ch)
{
    return (ch=='+' || ch == '-' || ch=='*' || ch=='/' || ch=='^');
}

bool isOperand(char ch)
{
    if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'))
        return true;
    return false;
}

int priority(char ch)
{
    if(ch=='^')
        return 3;
    else if(ch=='*' || ch=='/')
        return 2;
    else if(ch=='+' || ch=='-')
        return 1;
    return 0;
}


int main()
{
    string infix;
    cout<<"enter a infix string: "<<endl;
    cin>>infix;
    cout<<infix<<endl;
    stack<char> st;
    string postfix = "";
    int n = infix.size();
    for(int i=0;i<n;i++)
    {
        if(isOperand(infix[i]))
            postfix = postfix + infix[i];
        else if(infix[i]=='(')
            st.push(infix[i]);
        else if(infix[i]==')')
        {
            while(!st.empty() && st.top()!='(')
            {
                postfix = postfix+st.top();
                st.pop();
            }
            st.pop();
        }
        else if(isOperator(infix[i]))
        {
            while(!st.empty() && priority(st.top())>=priority(infix[i]))
            {
                if(st.top()=='^' && infix[i]=='^')
                    break;
                postfix = postfix + st.top();
                st.pop();
            }
            st.push(infix[i]);
        }
    }
    while(!st.empty())
    {
        postfix = postfix + st.top();
        st.pop();
    }
    cout<<"the postfix expression of given infix expression is: ";
    cout<<postfix<<endl;
    return 0;
}