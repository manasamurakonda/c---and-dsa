#include<bits/stdc++.h>
using namespace std;

class stck{
public:
    queue<int> q1,q2;
    void push(int x)
    {
        q2.push(x);
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
        cout<<x<<" pushed successfully"<<endl;
    }
    void pop()
    {
        if(q1.empty())
            cout<<"stack is empty"<<endl;
        else{
            cout<<"poped successfully"<<endl;
            q1.pop();
        }
    }
    int length()
    {
        cout<<"size of stack is: "<<q1.size()<<endl;
        return q1.size();
    }
    int peek()
    {
        if(q1.empty())
            cout<<"stack is empty"<<endl;
        else{
            cout<<"peek element is: "<<q1.front()<<endl;
            return q1.front();
        }
        return -1;
    }
    bool empty()
    {
        if(q1.empty())
            return true;
        return false;
    }
};

int main()
{
    stck st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.peek();
    st.pop();
    st.length();
    if(st.empty())
        cout<<"stack is empty"<<endl;
    else
        cout<<"stack is not empty"<<endl;
    return 0;
}