// level order traversal
// leetcode - 102
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root==NULL)
            return ans;
        q.push(root);
        while(!q.empty())
        {
            vector<int> x;
            int s = q.size();
            for(int i=1;i<=s;i++){
                TreeNode *temp = q.front();
                q.pop();
                if(temp->left!=NULL)
                    q.push(temp->left);
                if(temp->right!=NULL)
                    q.push(temp->right);
                x.push_back(temp->val);
            }
            ans.push_back(x);
        }
        return ans;
    }
};