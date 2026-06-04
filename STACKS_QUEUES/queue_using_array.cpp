#include<bits/stdc++.h>
using namespace std;
class que{
public:
    static const int N = 10;
    int arr[N];
    int front = -1;
    int rear = -1;
    int size = 0;
    void push(int x)
    {
        if(front == -1 && rear ==-1)
        {
            front = rear = 0;
            arr[rear]=x;
            cout<<x<<" pushed successfully"<<endl;
            size++;
        }
        else if((rear+1)%N == front)
            cout<<"queue is full"<<endl;
        else{
            rear = (rear+1)%N;
            arr[rear]=x;
            cout<<x<<" pushed successfully"<<endl;
            size++;
        }
    }
    void pop()
    {
        if(front==-1 && rear==-1)
            cout<<"queue is empty"<<endl;
        else if(front==rear)
        {
            front = rear = -1;
            size--;
            cout<<"poped successfully"<<endl;
        }
        else{
            front = (front+1)%N;
            size--;
            cout<<"poped successfully"<<endl;
        }
    }
    int peek()
    {
        if(rear == -1)
            cout<<"queue is empty"<<endl;
        else{
            cout<<"peek element is: "<<arr[front]<<endl;
            return arr[front];
        }
        return -1;
    }
    int length()
    {
        cout<<"size is: "<<size;
        return size;
    }
    bool empty()
    {
        if(front==-1 && rear == -1)
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
    cout<<q.arr[q.rear];
    return 0;
}