// intersection of two linked lists
// leetcode - 160

class Solution {
public:
    int length(ListNode *head)
    {
        int cnt = 0;
        ListNode *temp = head;
        while(temp!=NULL)
        {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        // brute -> hashing tc-o(m+n) sc-o(m+n)
        /*ListNode *temp1,*temp2;
        temp1 = headA;
        temp2 = headB;
        unordered_map<ListNode *,int> m;
        while(temp1!=NULL)
        {
            m[temp1]++;
            temp1 = temp1 ->next;
        }
        while(temp2!=NULL)
        {
            m[temp2]++;
            if(m[temp2] == 2)
                return temp2;
            temp2 = temp2->next;
        }
        return NULL;*/

        // better - finding lengths tc - o(m+2n) sc - o(1)
        /*int l1 = length(headA);
        int l2 = length(headB);
        int cnt = 0;
        ListNode *temp1,*temp2;
        temp1 = headA;
        temp2 = headB;
        if(l1>l2)
        {
            while(temp1!=NULL)
            {
                cnt++;
                if(cnt>l1-l2)
                    break;
                temp1 = temp1->next;
            }
        }
        else if(l2>l1)
        {
            while(temp2!=NULL)
            {
                cnt++;
                if(cnt>l2-l1)
                    break;
                temp2 = temp2 ->next;
            }
        }
        while(temp1!=NULL && temp2!=NULL)
        {
            if(temp1==temp2)
                return temp1;
            temp1 = temp1 -> next;
            temp2 = temp2 ->next;
        }
        return NULL;*/


        // optimal -> temp1 to head1 and temp2 to head2 tc-o(m+n) sc-o(1)
        ListNode *temp1,*temp2;
        temp1 = headA;
        temp2 = headB;
        if(headA==NULL || headB==NULL)
            return NULL;
        while(temp1!=NULL || temp2!=NULL)
        {
            if(temp1 == temp2)
                return temp1;
            if(temp1==NULL)
            {
                temp1 = headB;
                temp2 = temp2->next;
            }
            else if(temp2==NULL)
            {
                temp2 = headA;
                temp1 = temp1->next;
            }
            else{
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        return NULL;
    }
};