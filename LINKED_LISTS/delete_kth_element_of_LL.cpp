#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int d,Node *n)
    {
        data = d;
        next = n;
    }
};
Node* create()
{
    Node *head = NULL,*temp;
    bool flag = true;
    while(flag)
    {
        int ele;
        cout<< "enter element: ";
        cin>>ele;
        if(head == NULL)
        {
            temp = new Node(ele,NULL);
            head = temp;
        }
        else
        {
            temp-> next = new Node(ele,NULL);
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
    temp =head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int length(Node* head)
{
    int len = 0;
    Node* temp;
    temp = head;
    while(temp!=NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
Node* deletehead(Node* head)
{
    Node * temp;
    temp = head;
    head = head->next;
    free(temp);
    return head;
}
Node* deleteKth(Node* head,int k)
{
    if(k==1)
        return deletehead(head);
    int count=0;
    Node *temp,*temp1;
    temp = head;
    while(temp!=NULL)
    {
        count++;
        if(count==k-1)
        {
            temp1=temp;
        }
        if(count == k)
        {
            temp1->next=temp->next;
            break;
        }
        temp = temp->next;
    }
    free(temp);
    return head;
}
int main()
{
    Node *head;
    head = create();
    int k;
    cout<<"enter k: ";
    cin>>k;
    int n = length(head);
    if(k<=0 || k>n)
        cout<<"invalid k"<<endl;
    else{
        cout<<"before deletion: ";
        print(head);
        head = deleteKth(head,k);
        cout<<"after deletion: ";
        print(head);
    }
    return 0;
}