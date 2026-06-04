// merge two sorted linked lists
// leetcode - 21

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // brute -> creating another LL tc-o(m+n) sc-o(m+n)
        /*ListNode *ans;
        ans = NULL;
        ListNode *temp1,*temp2,*temp;
        temp1 = list1;
        temp2 = list2;
        while(temp1!=NULL && temp2!=NULL)
        {
            int ele;
            if(temp1->val<=temp2->val)
            {
                ele = temp1->val;
                temp1 = temp1->next;
            }
            else{
                ele = temp2->val;
                temp2 = temp2->next;
            }
            if(ans == NULL)
            {
                temp = new ListNode(ele,NULL);
                ans = temp;
            }
            else
            {
                temp->next = new ListNode(ele,NULL);
                temp = temp->next;
            }
        }
        while(temp1!=NULL)
        {
            if(ans == NULL)
            {
                temp = new ListNode(temp1->val,NULL);
                ans = temp;
            }
            else
            {
                temp->next = new ListNode(temp1->val,NULL);
                temp = temp->next;
            }
            temp1 = temp1->next;
        }
        while(temp2!=NULL)
        {
            if(ans == NULL)
            {
                temp = new ListNode(temp2->val,NULL);
                ans = temp;
            }
            else
            {
                temp->next = new ListNode(temp2->val,NULL);
                temp = temp->next;
            }
            temp2 = temp2->next;
        }
        return ans;*/

        // optimal -> changing links tc-o(m+n) sc-o(1)
        ListNode *temp1,*temp2;
        temp1 = list1;
        temp2 = list2;
        ListNode *dummy = new ListNode(-1,NULL);
        ListNode *temp;
        temp = dummy;
        while(temp1!=NULL && temp2!=NULL)
        {
            if(temp1->val<=temp2->val)
            {
                temp->next = temp1;
                temp1 = temp1->next;
            }
            else{
                temp->next = temp2;
                temp2 = temp2 ->next;
            }
            temp = temp->next;
        }
        while(temp1!=NULL)
        {
            temp->next = temp1;
            temp = temp->next;
            temp1 = temp1->next;
        }
        while(temp2!=NULL)
        {
            temp->next = temp2;
            temp = temp->next;
            temp2 = temp2->next;
        }
        return dummy->next;
    }
};