// GFG-find length of loop in LL

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // brute ->hasing tc-o(2n) sc-o(n)
        /*unordered_map<Node *,int> m;
        Node *temp;
        temp = head;
        int cnt= 1;
        while(temp!=NULL)
        {
            if(m.find(temp)!=m.end())
                return cnt-m[temp];
            m[temp] = cnt;
            cnt++;
            temp = temp->next;
        }
        return 0;*/
        
        // optimal -> tortoise and hare tc-o(2n) sc-o(1)
        int ans = 0;
        bool flag = false;
        Node *fast,*slow;
        fast = slow = head;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow){
                flag = true;
                break;
            }
        }
        if(flag==true)
        {
            ans++;
            slow = slow->next;
            while(slow!=fast)
            {
                ans++;
                slow = slow->next;
            }
        }
        return ans;
    }
};