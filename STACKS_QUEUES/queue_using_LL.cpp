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

class que{
public:
    Node *front = NULL;
    Node *rear = NULL;
    int size = 0;
    void push(int x)
    {
        Node *temp = new Node(x,NULL);
        if(front == NULL && rear == NULL)
        {
            front = rear = temp;
        }
        else{
            rear->next = temp;
            rear = rear->next;
        }
        size++;
        cout<<x<<" pushed successfully"<<endl;
    }
    void pop()
    {
        Node *temp;
        if(front == NULL && rear == NULL)
        {
            cout<<"queue is empty"<<endl;
        }
        else if(front == rear){
            temp = front;
            front = rear = NULL;
            delete temp;
            cout<<"poped successfully"<<endl;
        }
        else{
            temp = front;
            front = front->next;
            delete temp;
            cout<<"poped successfully"<<endl;
        }
        size--;
    }
    int peek()
    {
        if(front == NULL && rear == NULL)
        {
            cout<<"queue is empty"<<endl;
        }
        else{
            cout<<"peek element is: "<<front->data<<endl;
            return front->data;
        }
        return -1;
    }
    int length()
    {
        cout<<"size is: "<<size<<endl;
        return size;
    }
    bool empty()
    {
        if(front == NULL && rear == NULL)
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
    cout<<q.rear->data<<endl;
    return 0;
}