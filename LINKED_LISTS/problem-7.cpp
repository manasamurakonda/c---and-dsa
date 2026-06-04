// middle of the linked list
// leetcode - 876

class Solution {
public:
    int length(ListNode *head)
    {
        int cnt= 0;
        ListNode *temp = head;
        while(temp!=NULL)
        {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    ListNode* middleNode(ListNode* head) {
        // brute - finding length tc - o(n + n/2) sc - o(1)
        /*int n = length(head);
        int mid = (n/2)+1;
        ListNode * temp = head;
        while(temp!=NULL)
        {
            mid--;
            if(mid==0)
                return temp;
            temp = temp->next;
        }
        return NULL;*/


        // optimal - fast and slow pointers(tortoise and hare algo) tc - o(n) sc-o(1)
        ListNode *fast,*slow;
        fast = slow = head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};