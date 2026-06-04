// GFG - Delete all occurrences of a given key in a doubly linked list

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head, int x) {
        // optimal -> normal deletion in DLL tc-o(n) sc-o(1)
        Node *temp = *head,*temp1;
        while(temp!=NULL)
        {
            if(temp->data == x)
            {
                if(temp==*head)
                {
                    temp1 = temp;
                    temp = temp->next;
                    *head = temp;
                    (*head)->prev = NULL;
                    delete temp1;
                }
                else if(temp->next==NULL)
                {
                    temp1 = temp;
                    temp->prev->next=NULL;
                    temp = temp->next;
                    delete temp1;
                }
                else{
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    temp1 = temp;
                    temp = temp->next;
                    delete temp1;
                }
            }
            else temp = temp->next;
        }
    }
};