// remove nth node from end of LL
// leetcode - 19

class Solution {
public:
    int length(ListNode* head)
    {
        int cnt=0;
        ListNode *temp = head;
        while(temp!=NULL)
        {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // brute -> o(2n)
        /*int len = length(head);
        int k = len-n+1;
        ListNode *temp=head;
        int cnt = 0;
        if(k == 1)
        {
            temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        ListNode *temp1;
        while(temp!=NULL)
        {
            cnt++;
            if(cnt==k-1)
            {
                temp1 = temp->next;
                temp->next = temp->next->next;
                delete temp1;
                break;
            }
            temp = temp->next;
        }
        return head;*/

        // optimal -> fast slow pointers with n+1 gap tc-o(n)
        ListNode *fast,*slow;
        fast = head,slow = NULL;
        int cnt=  0;
        while(fast!=NULL)
        {
            cnt++;
            if(cnt>n){
                if(slow == NULL)
                    slow = head;
                else
                    slow = slow->next;
            }
            fast = fast->next;
        }
        if(slow == NULL)
        {
            slow = head;
            head = head->next;
            delete slow;
        }
        else{
            ListNode *temp;
            temp = slow->next;
            slow->next = slow->next->next;
            delete temp;
        }
        return head;
    }
};