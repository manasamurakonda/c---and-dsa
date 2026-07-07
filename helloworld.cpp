#include<bits/stdc++.h>
using namespace std;
class Node{
    public: 
        int data;
        Node *next;
        Node(int d)
        {
            data = d;
            next = NULL;
        }
};
int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    Node *head = NULL,*temp = NULL;
    for(int i=0;i<arr.size();i++)
    {
        if(head == NULL)
        {
            head = new Node(arr[i]);
            temp = head;
        }
        else{
            temp->next = new Node(arr[i]);
            temp = temp->next;
        }
    }
    cout<<"the linked list is: "<<endl;
    temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return 0;
}