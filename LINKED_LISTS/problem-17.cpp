// GFG - Remove duplicates from a sorted doubly linked list

class Solution {
  public:
    Node *removeDuplicates(struct Node *head) {
        // normal deletion of duplicates from sorted DLL tc-o(n) sc-o(1)
        Node *temp = head;
        Node *temp1=head->next;
        while(temp1!=NULL)
        {
            if(temp1->data==temp->data)
            {
                temp->next = temp1->next;
                
                delete temp1;
                temp1 = temp->next;
                if(temp1!=NULL)
                    temp1->prev = temp;
            }
            else
            {
                temp = temp->next;
                temp1 = temp1->next;
            }
        }
        return head;
    }
};