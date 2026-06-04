#include<bits/stdc++.h>
using namespace std;



class que{
public:
    stack<int> st1,st2;
    void push(int x)
    {
        st1.push(x);
        cout<<x<<" pushed successfully"<<endl;
    }
    void pop()
    {
        if(st2.empty() && st1.empty())
            cout<<"queue is empty"<<endl;
        else if(st2.empty())
        {
            while(!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
            cout<<"popped successfully"<<endl;
            st2.pop();
        }
        else{
            cout<<"popped successfully"<<endl;
            st2.pop();
        }
    }
    int peek()
    {
        if(st2.empty() && st1.empty())
            cout<<"queue is empty"<<endl;
        else if(st2.empty())
        {
            while(!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
            cout<<"the peek element is: "<<st2.top()<<endl;
            return st2.top();
        }
        else{
            cout<<"the peek element is: "<<st2.top()<<endl;
            return st2.top();
        }
        return -1;
    }
    int length()
    {
        cout<<"length of the queue is: "<<st1.size()+st2.size()<<endl;
        return st1.size()+st2.size();
    }
    bool empty()
    {
        if(st1.empty() && st2.empty())
            return true;
        return false;
    }
};

int main()
{
    que q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    q.push(10);
    q.push(11);
    q.pop();
    q.peek();
    q.length();
    if(q.empty())
        cout<<"queue is empty"<<endl;
    else cout<<"queue is not empty"<<endl;
    q.push(11);
    return 0;
}