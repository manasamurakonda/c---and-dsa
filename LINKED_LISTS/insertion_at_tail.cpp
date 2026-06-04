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

void print(Node *head)
{
    Node *temp;
    temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node * create()
{
    Node * head=NULL,*temp;
    bool flag = true;
    while(flag)
    {
        int ele;
        cout<<"enter ele: ";
        cin>>ele;
        if(head==NULL)
        {
            temp = new Node(ele,NULL);
            head = temp;
        }
        else{
            temp->next = new Node(ele,NULL);
            temp = temp->next;
        }
        cout<<"enter 1 to continue: ";
        cin>>flag;
    }
    return head;
}
Node * insertAtEnd(Node *head,int ele)
{
    if(head == NULL)
    {
        head = new Node(ele,NULL);
        return head;
    }
    Node *temp;
    temp = head;
    while(temp->next!=NULL)
        temp = temp->next;
    temp ->next = new Node(ele,NULL);
    return head;
}
int main()
{
    Node *head=NULL;
    head = create();
    int ele;
    cout<<"enter insertion element: ";
    cin>>ele;
    cout<<"linked list before insertion: ";
    print(head);
    head = insertAtEnd(head,ele);
    cout<<"linkedList after insertion: ";
    print(head);
    return 0;
}