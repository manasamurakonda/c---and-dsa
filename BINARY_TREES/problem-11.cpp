// GFG - bottom view of binary tree
class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // optimal -> vertical order traversal concept tc-o(n) sc-o(n)
        vector<int> ans;
        unordered_map<int,int> m;
        int mini = 0,maxi = 0;
        if(root == NULL)
            return ans;
        queue<pair<int,Node *>> q;
        q.push({0,root});
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                Node *temp = q.front().second;
                int vert = q.front().first;
                q.pop();
                m[vert] = temp->data;
                if(temp->left!=NULL)
                {
                    mini = min(mini,vert-1);
                    q.push({vert-1,temp->left});
                }
                if(temp->right!=NULL)
                {
                    maxi = max(maxi,vert+1);
                    q.push({vert+1,temp->right});
                }
            }
        }
        for(int i=mini;i<=maxi;i++)
            ans.push_back(m[i]);
        return ans;
    }
};