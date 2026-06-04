// GFG - Top View of Binary Tree
class Solution {
  public:
    vector<int> topView(Node *root) {
        //optimal -> vertical order traversal concept tc - o(nlogn) sc-o(n)
        vector<int> ans;
        map<int,int> m;
        if(root == NULL)
            return ans;
        queue<pair<int,Node *>> q;
        q.push({0,root});
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                int vert = q.front().first;
                Node *temp = q.front().second;
                q.pop();
                if(m.find(vert)==m.end())
                    m[vert] = temp->data;
                if(temp->left!= NULL)
                    q.push({vert-1,temp->left});
                if(temp->right!=NULL)
                    q.push({vert+1,temp->right});
            }
        }
        for(auto it : m)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};