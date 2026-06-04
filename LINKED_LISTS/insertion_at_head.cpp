#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node * next;
    Node(int d,Node *n)
    {
        data = d;
        next = n;
    }
};

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
Node * insertAtBegin(Node *head,int ele)
{
    Node* temp;
    temp = new Node(ele,NULL);
    temp->next = head;
    head = temp;
    return head;
}
int main()
{
    Node *head;
    head = create();
    int ele;
    cout<<"enter inserting element: ";
    cin>>ele;
    cout<<"before insertion: ";
    print(head);
    head = insertAtBegin(head,ele);
    cout<<"after insertion: ";
    print(head);
    return 0;
}