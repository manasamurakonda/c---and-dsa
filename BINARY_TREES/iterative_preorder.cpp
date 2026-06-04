// iterative preorder traversal
// leetcode - 144
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode *> st;
        if(root == NULL)
            return ans;
        st.push(root);
        while(!st.empty())
        {
            TreeNode *temp = st.top();
            st.pop();
            ans.push_back(temp->val);
            if(temp->right!=NULL)
                st.push(temp->right);
            if(temp->left!=NULL)
                st.push(temp->left);
        }
        return ans;
    }
};