// GFG - sort linked lists of 0's 1's and 2's
class Solution {
  public:
    Node* segregate(Node* head) {
        // brute - > counting 0,1,2's tc->o(2n)
        /*Node *temp=head;
        int zero = 0,one=0,two = 0;
        while(temp!=NULL)
        {
            if(temp->data==0)
                zero++;
            else if(temp->data==1)
                one++;
            else two++;
            temp = temp->next;
        }
        temp = head;
        while(temp!=NULL)
        {
            if(zero>0){
                temp->data = 0;
                zero--;
            }
            else if(one>0){
                temp->data = 1;
                one--;
            }
            else{
                temp->data = 2;
                two--;
            }
            temp = temp->next;
        }
        return head;*/
        
        // optimal -> 3 dummy nodes
        Node *dummy0 = new Node(-1);
        Node *dummy1 = new Node(-1);
        Node *dummy2 = new Node(-1);
        Node *temp0,*temp1,*temp2;
        temp0 = dummy0;
        temp1 = dummy1;
        temp2 = dummy2;
        Node *temp = head;
        while(temp!=NULL)
        {
            if(temp->data == 0)
            {
                temp0->next = temp;
                temp0 = temp0->next;
            }
            else if(temp->data == 1)
            {
                temp1->next = temp;
                temp1 = temp1->next;
            }
            else if(temp->data == 2)
            {
                temp2->next = temp;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        temp2->next = NULL;
        temp1->next = dummy2->next;
        temp0->next = dummy1->next;
        head = dummy0->next;
        return head;
    }
};