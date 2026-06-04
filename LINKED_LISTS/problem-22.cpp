// sort linked list
// leetcode - 148

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // brute -> storing in vector tc-o(nlogn + n) sc-o(n) 
        vector<int> ans;
        ListNode *temp = head;
        while(temp!=NULL)
        {
            ans.push_back(temp->val);
            temp = temp->next;
        }
        sort(ans.begin(),ans.end());
        temp = head;
        int n = ans.size();
        for(int i=0;i<n;i++)
        {
            temp->val = ans[i];
            temp = temp->next;
        }
        return head;

        // optimal -> quick or merge sort implementation on LL (pending)
    }
};