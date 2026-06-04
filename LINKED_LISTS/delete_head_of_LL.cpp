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
int main()
{
    Node *head=NULL,*temp = NULL;
    bool flag = true;
    int data;
    while(flag)
    {
        cout << "enter node data: "<< endl;
        cin>>data;
        if(head == NULL)
        {
            temp = new Node(data,NULL);
            head = temp;
        }
        else{
            temp -> next = new Node(data,NULL);
            temp = temp->next;
        }
        cout<< "to continue...enter 1 else enter 0: "<<endl;
        cin>>flag;
    }
    cout << "the linkedlist is: "<<endl;
    temp = head;
    while(temp!=NULL)
    {
        cout << temp->data<<" ";
        temp = temp->next;
    }
    //deleting head node
    temp = head;
    head = head->next;
    free(temp); // or delete temp;
    cout<<"linked list after deleting head" << endl;
    temp = head;
    while(temp!=NULL)
    {
        cout << temp->data<<" ";
        temp = temp->next;
    }
    return 0;
}