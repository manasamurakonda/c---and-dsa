// Add Two Numbers in LL
// leetcode - 2

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // optimal -> dummy node approach tc->max(n1,n2)
        ListNode *dummy;
        dummy = new ListNode(-1,NULL);
        ListNode *temp=dummy;
        ListNode *temp1 = l1,*temp2 = l2;
        long long sum=0,carry = 0;
        while(temp1!=NULL && temp2!=NULL)
        {
            int x = temp1->val+temp2->val+carry;
            sum = x%10;
            carry = x/10;
            temp ->next = new ListNode(sum,NULL);
            temp = temp->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while(temp1!=NULL)
        {
            int x = temp1->val+carry;
            sum = x%10;
            carry = x/10;
            temp ->next = new ListNode(sum,NULL);
            temp = temp->next;
            temp1 = temp1->next;
        }
        while(temp2!=NULL)
        {
            int x = temp2->val+carry;
            sum = x%10;
            carry = x/10;
            temp ->next = new ListNode(sum,NULL);
            temp = temp->next;
            temp2 = temp2->next;
        }
        if(carry!=0)
            temp->next = new ListNode(carry,NULL);
        return dummy->next;
    }
};