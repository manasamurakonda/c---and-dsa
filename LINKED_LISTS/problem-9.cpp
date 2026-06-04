// GFG - add 1 to a LL number

class Solution {
  public:
    Node * reverse(Node *head)
    {
        if(head == NULL || head->next == NULL)
            return head;
        Node *temp0,*temp1,*temp2;
        temp0 = NULL;
        temp1 = temp2 = head;
        while(temp2!=NULL)
        {
            temp2 = temp2->next;
            temp1->next = temp0;
            temp0 = temp1;
            temp1 = temp2;
        }
        return temp0;
    }
    int add1(Node *curr)
    {
        if(curr->next == NULL)
        {
            int carry = (curr->data+1)/10;
            curr ->data = (curr->data+1)%10;
            return carry;
        }
        int car = add1(curr->next);
        int carry = (curr->data+car)/10;
        curr ->data = (curr->data+car)%10;
        return carry;
    }
    Node* addOne(Node* head) {
        // optimal1 -> sum and carry tc-o(3n) sc-o(1)
        /*head = reverse(head);
        Node *temp = head,*temp1;
        int sum = 0,carry = 0;
        while(temp!=NULL)
        {
            if(temp==head)
            {
                sum = temp->data+1;
                carry = sum/10;
                sum = sum%10;
            }
            else{
                sum = temp->data+carry;
                carry = sum/10;
                sum = sum%10;
            }
            temp->data = sum;
            if(carry==0)
                break;
            temp1 = temp;
            temp = temp->next;
        }
        if(carry == 1)
            temp1->next = new Node(1);
        head = reverse(head);
        return head;*/
        
        // optimal2 -> recursion tc - o(n) sc-o(n)
        int carry = add1(head);
        if(carry==1)
        {
            Node *temp = new Node(1);
            temp->next = head;
            head = temp;
        }
        return head;
    }
};