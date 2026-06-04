// detect loop in LL
// leetcode - 141

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // brute - hashing tc-o(n) sc-o(n)
        /*ListNode *temp = head;
        unordered_map<ListNode *,int> m;
        while(temp!=NULL)
        {
            m[temp]++;
            if(m[temp]==2)
                return true;
            temp = temp->next;
        }
        return false;*/

        // optimal - tortoise & hare tc-o(n) sc-o(1)
        if(head==NULL || head->next==NULL)
            return false;
        ListNode *slow,*fast;
        slow = fast = head;
        do{
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)
                return true;;
        }while(fast!=NULL && fast->next!=NULL);
        return false;
    }
};