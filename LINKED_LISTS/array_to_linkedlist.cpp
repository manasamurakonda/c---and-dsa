#include<bits/stdc++.h>
using namespace std;
class Node
{
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
    vector<int> arr = {1,2,3,4,5};
    Node *head = NULL;
    Node * mover;
    for(int i=0;i<arr.size();i++)
    {
        if(head == NULL)
        {
            head = new Node(arr[i],NULL);
            mover = head;
        }
        else{
            mover->next = new Node(arr[i],NULL);
            mover = mover->next;
        }
    }
    cout << "the linked list is: "<< endl;
    mover = head;
    // traversal in linked list
    while(mover!=NULL)
    {
        cout << mover->data << " ";
        mover = mover->next;
    }
    return 0;
}