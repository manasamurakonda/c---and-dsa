// reverse node in k group
// leetcode - 25

class Solution {
public:
    ListNode * reverse(ListNode *head,int s,int e)
    {
        ListNode *start=NULL,*end=NULL,*temp0=NULL,*temp1=NULL,*temp2=NULL;
        int cnt = 0;
        temp0 = head;
        while(temp0!=NULL)
        {
            cnt++;
            if(cnt==s-1)
                start = temp0;
            if(cnt == e+1){
                end = temp0;
                break;
            }
            temp0 = temp0->next;
        }
        temp0 = start;
        if(start!=NULL){
            temp1 = temp2 = start->next;
        }
        else temp1 = temp2 = head;
        while(temp2!=end)
        {
            temp2 = temp2->next;
            temp1->next = temp0;
            temp0 = temp1;
            temp1 = temp2;
        }
        if(start==NULL){
            head->next = end;
            head = temp0;
        }
        else{
            if(start->next!=NULL)
            start->next->next = end;
            start->next = temp0;
        }
        return head;
    }
    void reversal(ListNode *head)
    {
        ListNode *temp0,*temp1,*temp2;
        temp0 = NULL;
        temp1 = temp2 = head;
        while(temp2!=NULL)
        {
            temp2 = temp2 ->next;
            temp1->next = temp0;
            temp0 = temp1;
            temp1 = temp2;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        // my idea - reversing specific part of LL
        /*ListNode * temp = head,*temp1=head;
        int s,e,cnt = 0;
        s=1,e = 0;
        while(temp!=NULL)
        {
            cnt++;
            if(cnt%k==0)
            {
                e = cnt;
                head = reverse(head,s,e);
                s=e+1;
                temp = temp1;
                temp1 = temp1->next;
            }
            temp = temp->next;
        }
        return head;*/

        // strivers idea -> breaking links and reversing
        ListNode *temp,*knode,*next,*prev;
        temp = head;
        while(temp!=NULL)
        {
            int cnt = 0;
            ListNode *itr = temp;
            while(itr!=NULL)
            {
                cnt++;
                if(cnt == k)
                    break;
                itr = itr->next;
            }
            if(itr==NULL)
                return head;
            knode = itr;
            next = knode->next;
            knode->next = NULL;
            reversal(temp);
            if(temp == head)
            {
                head = knode;
                temp->next = next;
                prev = temp;
            }
            else{
                prev->next = knode;
                temp->next = next;
                prev = temp;
            }
            temp = next;
        }
        return head;
    }
};