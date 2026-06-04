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
int length(Node *head)
{
    int ans = 0;
    Node *temp;
    temp = head;
    while(temp!=NULL)
    {
        ans++;
        temp = temp->next;
    }
    return ans;
}
Node* insertBeforeK(Node *head,int ele,int k)
{
    int count=1;
    Node *temp,*temp1;
    if(k==1)
    {
        temp = new Node(ele,NULL);
        temp->next=head;
        head=temp;
        return head;
    }
    else{
        temp = head;
        while(count<k-1)
        {
            temp = temp->next;
            count++;
        }
        temp1 = new Node(ele,NULL);
        temp1->next = temp->next;
        temp->next=temp1;
    }
    return head;
}
int main()
{
    Node *head = NULL;
    head = create();
    int k,n;
    cout<<"enter k: ";
    cin>>k;
    n = length(head);
    if(k<=0 || k>n+1)
        cout<<"invalid k value";
    else{
        int ele;
        cout<<"before insertion : ";
        print(head);
        cout<<"enter insertion element: ";
        cin>>ele;
        head = insertBeforeK(head,ele,k);
        cout<<"after insertion: ";
        print(head);
    }
    return 0;
}