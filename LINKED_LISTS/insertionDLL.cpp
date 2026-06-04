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
Node * create()
{
    Node *head = NULL;
    Node * temp;
    bool flag = true;
    while(flag)
    {
        int ele;
        cout<<"enter element: ";
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
        cout<<"enter 0 to discontinue: ";
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

Node * insertHead(Node *head,int ele)
{
    Node *temp;
    if(head == NULL)
    {
        head = new Node(ele,NULL,NULL);
        return head;
    }
    temp = new Node(ele,NULL,NULL);
    head->prev = temp;
    temp->next = head;
    head = temp;
    return head;
}

Node * insertTail(Node *head,int ele)
{
    Node *temp;
    if(head == NULL)
    {
        head = new Node(ele,NULL,NULL);
        return head;
    }
    temp = head;
    while(temp->next!=NULL)
        temp = temp->next;
    temp->next = new Node(ele,NULL,NULL);
    temp->next->prev = temp;
    return head;
}

Node * insertK(Node *head,int ele,int k)
{
    Node *temp;
    int cnt = 0;
    if(k==1)
        return insertHead(head,ele);
    else if(k==length(head)+1)
        return insertTail(head,ele);
    temp = head;
    while(temp!=NULL)
    {
        cnt++;
        if(cnt==k)
            break;
        temp = temp->next;
    }
    Node *temp1 = new Node(ele,NULL,NULL);
    temp1->prev = temp->prev;
    temp1->next = temp;
    temp->prev->next = temp1;
    temp->prev = temp1;
    return head;
}

int main()
{
    Node * head=NULL;
    head = create();
    cout<<"DLL before insertion is: ";
    print(head);
    int ele;
    cout<<"enter insertion element: ";
    cin>>ele;
    head = insertHead(head,ele);
    head = insertTail(head,ele);
    cout<<"after insertion the DLL is: ";
    print(head);
    int n = length(head);
    int k;
    cout<<"enter k: ";
    cin>>k;
    if(k<=0 && k>n+1)
        cout<<"invalid k";
    else{
        head = insertK(head,ele,k);
    }
    cout<<"after insertion: ";
    print(head);
    return 0;
}