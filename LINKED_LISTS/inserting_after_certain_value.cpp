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
Node * create()
{
    Node *head=NULL,*temp;
    bool flag = true;
    while(flag)
    {
        int ele;
        cout<<"enter element: ";
        cin>>ele;
        if(head == NULL)
        {
            temp = new Node(ele,NULL);
            head = temp;
        }
        else{
            temp->next = new Node(ele,NULL);
            temp = temp->next;
        }
        cout<<"enter 0 to stop: ";
        cin>>flag;
    }
    return head;
}
void print(Node *head)
{
    Node *temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
Node * insertionAfterVal(Node *head,int val,int ele)
{
    if(head == NULL)
        return NULL;
    Node *temp,*temp1;
    temp = head;
    while(temp!=NULL)
    {
        if(temp->data == val)
        {
            temp1 = new Node(ele,NULL);
            temp1->next = temp->next;
            temp->next = temp1;
            break;
        }
        temp = temp->next;
    }
    return head;
}
int main()
{
    Node *head;
    head = create();
    cout<<"before insertion: ";
    print(head);
    int val,ele;
    cout<<"enter val: ";
    cin>>val;
    cout<<"enter ele: ";
    cin>>ele;
    head = insertionAfterVal(head,val,ele);
    cout<<"after insertion: ";
    print(head);
    return 0;
}