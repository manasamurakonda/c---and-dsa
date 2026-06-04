// Odd Even Linked List
// leetcode - 328

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        // brute -> store in vector and then modify data of LL tc-o(n) sc-o(n)

        // optimal-1(not recommended) my approach (insertion and deletion)
        /*if(head == NULL || head->next ==NULL)
            return head;
        int cnt = 0;
        ListNode * temp,*temp1,*ins;
        temp = temp1 = ins = head;
        while(temp!=NULL)
        {
            cnt++;
            if(cnt%2!=0 && cnt!=1)
            {
                // insertion
                ins->next = new ListNode(temp->val,ins->next);
                ins = ins->next;

                // deletion
                temp1->next = temp->next;
                cout<<temp->val<<" ";
                delete temp;
                temp = temp1->next;
            }
            else{
                temp1 = temp;
                temp = temp->next;
            }
        }
        return head;*/

        // optimal2 -> (strivers approach(links marchadamey)) tc-o(n) sc-o(1)
        if(head == NULL || head->next==NULL)
            return head;
        ListNode *head1,*odd,*even;
        head1 = head->next;
        odd= head;
        even = head1;
        while(even!=NULL && even->next!=NULL)
        {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = head1;
        return head;
    }
};