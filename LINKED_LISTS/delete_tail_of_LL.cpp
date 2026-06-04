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

Node* create()
{
    Node *head=NULL;
    Node *temp;
    bool flag = true;
    while(flag)
    {
        int ele;
        cout << "enter node element: "<<endl;
        cin>> ele;
        if(head==NULL)
        {
            temp = new Node(ele,NULL);
            head = temp;
        }
        else{
            temp-> next = new Node(ele,NULL);
            temp = temp->next;
        }
        cout << "to continue...enter 1...else enter 0: "<<endl;
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
        cout<< temp->data<<" ";
        temp = temp->next;
    }
}
Node * deleteTail(Node * head)
{
    if(head==NULL || head->next==NULL)
        return NULL;
    Node *temp,*temp1;
    temp = head;
    temp1 = head;
    while(temp->next!=NULL)
    {
        temp1= temp;
        temp = temp->next;
    }
    temp1->next = NULL;
    free(temp);
    return head;
}
int main()
{
    Node *head;
    head = create();
    cout << "before deletion: "<<endl;
    print(head);
    head = deleteTail(head);
    cout<< "\nafter deletion: "<<endl;
    print(head);
    return 0;
}