// palindrome linked list
// leetcode - 234

class Solution {
public:
    ListNode * reverse(ListNode *cur,ListNode *prev)
    {
        if(cur == NULL)
            return prev;
        ListNode *head = reverse(cur->next,cur);
        cur->next = prev;
        return head;
    }
    ListNode * reverseI(ListNode *head)
    {
        ListNode *temp0,*temp1,*temp2;
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
    bool isPalindrome(ListNode* head) {
        // brute -> using vector tc-o(2n) sc-o(n)
        /*vector<int> ans;
        ListNode *temp = head;
        while(temp!=NULL)
        {
            ans.push_back(temp->val);
            temp = temp->next;
        }
        int n = ans.size();
        int l=0,r=n-1;
        while(l<=r)
        {
            if(ans[l]!=ans[r])
                return false;
            l++;
            r--;
        }
        return true;*/

        
        // optimal -> tortoise hare and reversing half LL and comparing tc - o(2n) sc - o(1)
        ListNode *fast,*slow;
        fast = slow = head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // ListNode * head1 = reverse(slow->next,NULL);
        ListNode *head1 = reverseI(slow->next);
        fast = head;
        slow = head1;
        while(slow!=NULL)
        {
            if(fast->val!=slow->val){
                head1 = reverseI(head1);
                return false;
            }
            fast = fast->next;
            slow = slow->next;
        }
        head1 = reverseI(head1);
        return true;
    }
};