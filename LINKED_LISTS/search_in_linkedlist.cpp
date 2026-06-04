#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node * next;
    Node(int d,Node *n)
    {
        data = d;
        next = n;
    }
};
int main()
{
    int x;
    bool flag = true;
    Node * head=NULL;
    Node *temp;
    while(flag)
    {
        int ele;
        cout<< "enter element: ";
        cin>>ele;
        if(head==NULL)
        {
            temp = new Node(ele,NULL);
            head = temp;
        }
        else{
            temp->next = new Node(ele,NULL);
            temp = temp-> next;
        }
        cout << "to continue enter 1 else enter 0: ";
        cin>>flag;
    }
    cout << "enter target element: "<<endl;
    cin>> x;
    temp = head;
    while(temp!=NULL)
    {
        if(temp->data==x){
            cout << "element found";
            flag = true;
        }
        temp = temp->next;
    }
    if(!flag)
    {
        cout << " element not found"<<endl;
    }
    return 0;
}