// find the starting point of loop in LL
// leetcode - 142

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // brute -> hashing tc-o(n) sc-o(n)
        /*ListNode *temp = head;
        unordered_map<ListNode *,int> m;
        while(temp!=NULL)
        {
            m[temp]++;
            if(m[temp]==2)
                return temp;
            temp = temp -> next;
        }
        return NULL;*/

        // optimal -> tortoise hare tc - o(n) sc-o(1)
        bool flag = false;
        ListNode *slow,*fast;
        slow = fast = head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow -> next;
            fast = fast -> next ->next;
            if(slow == fast){
                flag = true;
                break;
            }
        }
        if(flag==false)
            return NULL;
        slow = head;
        while(slow!=fast)
        {
            slow = slow->next;
            fast = fast ->next;
        }
        return slow;
    }
};