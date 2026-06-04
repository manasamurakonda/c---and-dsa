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
        if(temp->prev!=NULL)
            cout<<temp->prev->data<<" ";
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
Node * array_to_DLL(vector<int> &arr)
{
    Node *head = NULL,*temp;
    for(int i=0;i<arr.size();i++)
    {
        if(head == NULL)
        {
            temp = new Node(arr[i],NULL,NULL);
            head = temp;
        }
        else{
            temp->next = new Node(arr[i],NULL,NULL);
            temp->next->prev = temp;
            temp = temp->next;
        }
    }
    return head;
}
int main()
{
    // creating and printing DLL
    /*Node * head;
    head = create();
    print(head);
    cout<<endl;*/

    // converting array into DLL
    Node *head1=NULL;
    vector<int> arr = {10,100,1000,10000,100000,1000000,10000000,100000000};
    head1 = array_to_DLL(arr);
    cout<<"the DLL is: ";
    print(head1);
    return 0;
}