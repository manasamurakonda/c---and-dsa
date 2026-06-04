// GFG - Find pairs with given sum in doubly linked list

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // brute -> nested loops tc-o(n^2) sc-o(1)
        /*vector<pair<int,int>> ans;
        Node *temp1,*temp2;
        temp1 = head;
        while(temp1!=NULL)
        {
            temp2 = temp1->next;
            while(temp2!=NULL)
            {
                if(temp1->data+temp2->data == target)
                    ans.push_back({temp1->data,temp2->data});
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        return ans;*/
        
        // better -> hashing tc-o(nlogn) sc-o(n)
        /*vector<pair<int,int>> ans;
        Node *temp;
        temp = head;
        unordered_map<int,int> m;
        while(temp!=NULL)
        {
            if(m.find(target-temp->data)!=m.end())
                ans.push_back({target-temp->data,temp->data});
            m[temp->data]++;
            temp = temp->next;
        }
        sort(ans.begin(),ans.end());
        return ans;*/
        
        // optimal -> two pointers tc-o(n) sc-o(1)
        Node *temp1=head;
        Node *temp2 = head;
        vector<pair<int,int>> ans;
        while(temp2->next!=NULL)
            temp2 = temp2->next;
        while(temp1!=temp2 && temp2->next!=temp1)
        {
            if(temp1->data+temp2->data==target)
            {
                ans.push_back({temp1->data,temp2->data});
                temp1 = temp1->next;
                temp2 = temp2->prev;
            }
            else if(temp1->data+temp2->data>target)
                temp2 = temp2 ->prev;
            else temp1 = temp1->next;
        }
        return ans;
    }
};
