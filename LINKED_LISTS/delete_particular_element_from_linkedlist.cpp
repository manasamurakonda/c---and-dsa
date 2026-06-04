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
    Node *head,*temp;
    head = NULL;
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
        cout<<"enter 1 to countinue...else enter 0: ";
        cin>>flag;
    }
    return head;
}
void print(Node *head)
{
    Node *temp;
    temp = head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
Node * deleteEle(Node * head,int ele)
{
    if(head == NULL)
        return head;
    Node * temp = head;
    if(head->data == ele)
    {
        head = head->next;
        free(temp);
        return head;
    }
    Node *temp1=head;
    while(temp!=NULL)
    {
        if(temp->data == ele)
        {
            temp1->next = temp->next;
            free(temp);
            break;
        }
        temp1 = temp;
        temp = temp->next;
    }
    return head;
}
int main()
{
    Node *head;
    head = create();
    int ele;
    cout<<"enter target element: ";
    cin>>ele;
    cout<<"before deletion: ";
    print(head);
    head = deleteEle(head,ele);
    cout<< "after deletion: ";
    print(head);
    return 0;
}