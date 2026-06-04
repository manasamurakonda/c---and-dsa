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
Node* create()
{
    Node *head=NULL, *temp;
    bool flag = true;
    while(flag)
    {
        int ele;
        cout<<"enter ele: ";
        cin>>ele;
        if(head==NULL)
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
void print(Node * head)
{
    cout<<"the doubly LL is: "<<endl;
    Node * temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
Node * delete_head(Node *head)
{
    Node *temp;
    if(head == NULL)
        return NULL;
    else if(head->next==NULL)
    {
        free(head);
        return NULL;
    }
    temp = head;
    head = head->next;
    head->prev =NULL;
    free(temp);
    return head;
}
Node * delete_tail(Node *head)
{
    if(head == NULL)
        return NULL;
    else if(head->next==NULL)
    {
        free(head);
        return NULL;
    }
    Node *temp;
    temp = head;
    while(temp->next!=NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
    return head;
}
int length(Node *head)
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
Node * deletingk(Node *head,int k)
{
    int cnt = 0;
    Node *temp;
    temp = head;
    if(k==1)
    {
        return delete_head(head);
    }
    else if(k==length(head))
        return delete_tail(head);
    while(temp!=NULL)
    {
        cnt++;
        if(cnt==k)
            break;
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    return head;
}
int main()
{
    Node *head=NULL;
    head = create();
    cout<<"before deletion: ";
    print(head);
    head = delete_head(head);
    cout<<"after deletion: ";
    print(head);
    head = delete_tail(head);
    cout<<"after deletion: ";
    print(head);
    int k;
    cout<<"enter k: ";
    cin>>k;
    int n = length(head);
    if(k<=0 || k>n)
        cout<<"invalid k";
    else{
        head = deletingk(head,k);
        cout<<"after deletion: ";
        print(head);
    }
    // deleting a specific node -> migili undhi..but u can do it
    return 0;
}