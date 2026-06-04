#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int d,Node *p,Node *n)
    {
        data = d;
        prev = p;
        next = n;
    }
};
Node * create()
{
    Node *head=NULL;
    Node *temp;
    bool flag = true;
    while(flag)
    {
        int ele;
        cout<<"enter ele: ";
        cin>>ele;
        if(head == NULL)
        {
            temp = new Node(ele,NULL,NULL);
            head = temp;
        }
        else{
            temp->next = new Node(ele,NULL,NULL);
            temp->next->prev = temp;
            temp = temp->next;
        }
        cout<<"enter 0 to stop: ";
        cin>>flag;
    }
    return head;
}
void display(Node *head)
{
    Node *temp = head;
    while(temp!=NULL)
    {
        if(temp->prev!=NULL)
            cout<<temp->prev->data<<" ";
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
Node * reversal(Node * head)
{
    // we can just swap next and prev of all the nodes while moving through curr prev(another method)
    // can also just modify the data using stack
    Node *temp1,*temp2,*temp3;
    temp1 = NULL;
    temp2 = temp3 = head;
    while(temp3!=NULL)
    {
        temp3=temp3->next;
        temp2->prev = temp3;
        temp2->next = temp1;
        temp1 = temp2;
        temp2 = temp3;
    }
    return temp1;
}
int main()
{
    Node *head;
    head = create();
    cout<<"before reversal: ";
    display(head);
    head = reversal(head);
    cout<<"after reversal: ";
    display(head);
    return 0;
}