// merge k sorted lists
// leetcode -23

class Solution {
public:
    ListNode* merge2LL(ListNode *head1,ListNode *head2)
    {
        ListNode *dummy = new ListNode(-1,NULL);
        ListNode *temp1,*temp2,*temp;
        temp = dummy;
        temp1 = head1;
        temp2 = head2;
        while(temp1!=NULL && temp2!=NULL)
        {
            if(temp1->val<=temp2->val)
            {
                temp->next = temp1;
                temp1 = temp1->next;
            }
            else{
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        while(temp1!=NULL)
        {
            temp->next = temp1;
            temp1 = temp1->next;
            temp = temp->next;
        }
        while(temp2!=NULL)
        {
            temp->next = temp2;
            temp2 = temp2->next;
            temp = temp->next;
        }
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // brute -> converting into array and sorting
        /*vector<int> ans;
        int n = lists.size();
        for(int i=0;i<n;i++)
        {
            ListNode * head,*temp;
            head = lists[i];
            temp = head;
            while(temp!=NULL)
            {
                ans.push_back(temp->val);
                temp = temp->next;
            }
        }
        ListNode *dummy,*temp;
        dummy = new ListNode(-1,NULL);
        int n1 = ans.size();
        sort(ans.begin(),ans.end());
        temp = dummy;
        for(int i=0;i<n1;i++)
        {
            temp->next = new ListNode(ans[i],NULL);
            temp = temp->next;
        }
        return dummy->next;*/

        // better -> using concept of merging two sorted LL
        int n = lists.size();
        if(n==0)
            return NULL;
        else if(n==1)
            return lists[0];
        ListNode *merged = merge2LL(lists[0],lists[1]);
        for(int i=2;i<n;i++)
        {
            merged = merge2LL(merged,lists[i]);
        }
        return merged;

        // optimal -> using min heap(pending)
    }
};