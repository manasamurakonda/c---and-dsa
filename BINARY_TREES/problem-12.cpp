// right view of binary tree
// leetcode - 199
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        // better -> level order traversal concept tc-o(n) sc-o(2n)
        /*vector<int> ans;
        if(root == NULL)
            return ans;
        queue<pair<int,TreeNode *>> q;
        q.push({0,root});
        unordered_map<int,int> m;
        int maxi = 0;
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                int level = q.front().first;
                TreeNode * temp = q.front().second;
                q.pop();
                m[level] = temp->val;
                maxi = max(maxi,level);
                if(temp->left!=NULL)
                    q.push({level+1,temp->left});
                if(temp->right!=NULL)
                    q.push({level+1,temp->right});
            }
        }
        for(int i=0;i<=maxi;i++)
            ans.push_back(m[i]);
        return ans;*/

        // optimal -> level order traversal concept(space optimized) tc-o(n) sc-o(n)
        vector<int> ans;
        if(root == NULL)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                TreeNode * temp = q.front();
                q.pop();
                if(i==sz-1)
                    ans.push_back(temp->val);
                if(temp->left!=NULL)
                    q.push(temp->left);
                if(temp->right!=NULL)
                    q.push(temp->right);
            }
        }
        return ans;
    }
};