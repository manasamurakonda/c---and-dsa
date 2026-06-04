// reverse a singly LL
// leetcode -206

class Solution {
public:
    ListNode * rev(ListNode *cur,ListNode *prev)
    {
        if(cur==NULL)
            return prev;
        ListNode * head = rev(cur->next,cur);
        cur->next = prev;
        return head;
    }
    ListNode* reverseList(ListNode* head) {
        // brute - storing data of nodes in stack tc-o(2n) sc-o(n)

        //better -> recursive approach tc-o(n) sc-o(n)
        // return rev(head,NULL);


        // optimal iteative approach tc-o(n) sc-o(1)
        ListNode *temp0,*temp1,*temp2;
        if(head == NULL || head->next==NULL)
            return head;
        temp0 = NULL;
        temp1 = temp2 = head;
        while(temp2!=NULL)
        {
            temp2 = temp2 ->next;
            temp1->next = temp0;
            temp0 = temp1;
            temp1 = temp2;
        }
        return temp0;
    }
};