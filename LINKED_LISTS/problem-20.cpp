// rotate linked list
// leetcode - 61

class Solution {
public:
    int length(ListNode *head)
    {
        int len = 0;
        ListNode *temp = head;
        while(temp!=NULL)
        {
            len++;
            temp = temp->next;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        // optimal -> just changing links tc-o(2n) sc-o(1)
        int n = length(head);
        if(head==NULL)
            return NULL;
        if(k>=n)
        {
            k = k%n;
        }
        if(k==0)
            return head;
        ListNode *slow,*fast;
        slow = fast = NULL;
        int cnt = 1;
        if(k>=n)
        {
            k = k%n;
        }
        fast = head;
        while(fast->next!=NULL)
        {
            cnt++;
            if(cnt==k+1)
            {
                slow = head;
            }
            else if(slow!=NULL)
                slow = slow->next;
            fast = fast->next;
        }
        fast ->next = head;
        head = slow->next;
        slow->next = NULL;
        return head;
    }
};