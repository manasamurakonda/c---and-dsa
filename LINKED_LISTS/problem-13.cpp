// delete the middle node of a LL
// leetcode - 2095

class Solution {
public:
    int length(ListNode *head)
    {
        int cnt = 0;
        ListNode *temp=head;
        while(temp!=NULL)
        {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    ListNode* deleteMiddle(ListNode* head) {
        // brute - finding length tc-o(n+n/2) sc-o(1)
        /*int n = length(head);
        if(n==1)
            return NULL;
        int mid = (n/2)+1;
        ListNode *temp = head;
        while(temp!=NULL)
        {
            mid--;
            if(mid==1)
                break;
            temp = temp->next;
        }
        ListNode *temp1;
        temp1 = temp->next;
        temp->next = temp->next->next;
        delete temp1;
        return head;*/

        // optimal -tortoise and hare tc-o(n/2) sc-o(1)
        ListNode *slow,*fast;
        slow = head;
        fast = head;
        ListNode *temp1;
        temp1 = head;
        if(head==NULL || head->next ==NULL)
            return NULL;
        while(fast!=NULL && fast->next!=NULL)
        {
            temp1 = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp1->next = temp1->next->next;
        delete slow;
        return head;
    }
};