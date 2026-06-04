#include<bits/stdc++.h>
using namespace std;


bool isOperator(char ch)
{
    return (ch=='+' || ch=='-' || ch=='/' || ch=='*' || ch=='^');
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
    else if(ch=='/' || ch=='*')
        return 2;
    else if(ch=='+' || ch=='-')
        return 1;
    return 0;
}
int main()
{
    string infix;
    cout<<"enter a infix expression: "<<endl;
    cin>>infix;
    int n = infix.size();
    string prefix = "";
    reverse(infix.begin(),infix.end());
    stack<char> st;
    for(int i=0;i<n;i++)
    {
        char ch = infix[i];
        if(isOperand(ch))
            prefix = prefix + ch;
        else if(ch == '(')
        {
            while(!st.empty() && st.top()!=')')
            {
                prefix = prefix + st.top();
                st.pop();
            }
            if(!st.empty())
                st.pop();
        }
        else if(ch == ')')
            st.push(ch);
        else if(isOperator(ch))
        {
            if(ch=='^')
            {
                while(!st.empty() && priority(ch)>=priority(st.top()))
                {
                    prefix = prefix + st.top();
                    st.pop();
                }
                st.push(ch);
            }
            else{
                while(!st.empty() && priority(st.top())>priority(ch))
                {
                    prefix = prefix + st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }
    }
    while(!st.empty())
    {
        prefix = prefix + st.top();
        st.pop();
    }
    reverse(prefix.begin(),prefix.end());
    cout<<"the prefix expression of given infix expression is: ";
    cout<<prefix<<endl;
    return 0;
}