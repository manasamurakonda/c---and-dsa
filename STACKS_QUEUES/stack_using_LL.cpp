#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int d,Node *n)
    {
        data = d;
        next = n;
    } 
};

class stck{
public:
    Node *top = NULL;
    int size = 0;
    void push(int x)
    {
        Node *temp = new Node(x,NULL);
        if(top == NULL)
        {
            top = temp;
        }
        else{
            temp->next = top;
            top = temp;
        }
        cout<<x<<" pushed successfully"<<endl;
        size++;
    }
    void pop()
    {
        if(top == NULL)
            cout<<"stack is empty"<<endl;
        else{
            Node *temp;
            temp = top;
            top = top->next;
            delete temp;
            size--;
            cout<<"poped successfully"<<endl;
        }
    }
    int peek()
    {
        if(top == NULL)
        {
            cout<<"stack is empty"<<endl;
            return -1;
        }
        else{
            cout<<"peek element is "<<top->data<<endl;
            return top->data;
        }
    }
    int length()
    {
        cout<<"length of stack is: "<<size<<endl;
        return size;
    }
    bool empty()
    {
        if(top == NULL)
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