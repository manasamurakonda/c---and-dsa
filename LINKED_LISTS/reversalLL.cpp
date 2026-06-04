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
        cout<<"enter ele: ";
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
void display(Node *head)
{
    Node *temp;
    temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
Node * reverse(Node *head)
{
    Node *temp1,*temp2,*temp3;
    temp1 = NULL;
    temp2 = head;
    temp3 = head;
    while(temp3!=NULL)
    {
        temp3 = temp3->next;
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
    head = reverse(head);
    cout<<"after reversal: ";
    display(head);
    return 0;
}