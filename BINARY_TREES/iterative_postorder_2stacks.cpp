// iterative postorder traversal
// leetcode - 145
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode *> st1;
        stack<TreeNode *> st2;
        if(root==NULL)
            return ans;
        st1.push(root);
        while(!st1.empty())
        {
            TreeNode *temp = st1.top();
            st1.pop();
            st2.push(temp);
            if(temp->left!=NULL)
                st1.push(temp->left);
            if(temp->right!=NULL)
                st1.push(temp->right);
        }
        while(!st2.empty())
        {
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;
    }
};