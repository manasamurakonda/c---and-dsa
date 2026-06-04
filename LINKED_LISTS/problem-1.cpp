// doubly linked list reversal
// GFG - Reverse a Doubly Linked List

class Solution {
  public:
    Node * reversal(Node *head)
    {

        // brute -> using stack
        //better ->using 3 pointers
        // optimal -> swapping prev and next of current node and moving to prev
        if(head==NULL || head->next==NULL)
            return head;
        Node *temp,*curr;
        curr = head;
        temp = NULL;
        while(curr!=NULL)
        {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr  = curr->prev;
        }
        return temp->prev;
    }
    Node *reverse(Node *head) {
        head = reversal(head);
        return head;
    }
};