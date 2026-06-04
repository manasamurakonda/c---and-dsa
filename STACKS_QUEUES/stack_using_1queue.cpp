#include<bits/stdc++.h>
using namespace std;


class stck{
public:
    queue<int> q;
    void push(int x)
    {
        q.push(x);
        int n = q.size();
        for(int i=1;i<n;i++)
        {
            q.push(q.front());
            q.pop();
        }
        cout<<x<<" pushed successfully"<<endl;
    }
    void pop()
    {
        if(q.empty())
            cout<<"stack is empty"<<endl;
        else{
            cout<<"poped successfully"<<endl;
            q.pop();
        }
    }
    int peek()
    {
        if(q.empty())
            cout<<"stack is empty"<<endl;
        else{
            cout<<"the peek element is: "<<q.front()<<endl;
            return q.front();
        }   
        return -1;
    }
    int length()
    {
        cout<<"the length of the stack is: "<<q.size()<<endl;
        return q.size();
    }
    bool empty()
    {
        if(q.empty())
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
    return 0;
}