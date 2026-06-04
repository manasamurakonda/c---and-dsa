// flatten a binary tree into linkedlist
// leetcode - 114

class Solution {
public:
    void preorder(TreeNode *root,vector<TreeNode *> &pre)
    {
        if(root == NULL)
            return;
        pre.push_back(root);
        preorder(root->left,pre);
        preorder(root->right,pre);
    }
    void rev_post(TreeNode *root,TreeNode *&prev)
    {
        if(root == NULL)
            return;
        rev_post(root->right,prev);
        rev_post(root->left,prev);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
    void flatten(TreeNode *root) {
        // brute -> using a preorder vector of nodes tc-o(2n) sc-o(2n)
        /*vector<TreeNode *> pre;
        preorder(root,pre);
        int n = pre.size();
        for(int i=0;i<n-1;i++)
        {
            pre[i]->left = NULL;
            pre[i]->right = pre[i+1]; 
        }*/

        // better1-> reverse postorder traversal tc-o(n) sc-o(n)
        /*TreeNode *prev = NULL;
        rev_post(root,prev);*/

        // better2 -> reverse postorder traversal using stack tc-o(n) sc-o(n)
        /*stack<TreeNode *> st;
        if(root)
            st.push(root);
        while(!st.empty())
        {
            TreeNode *temp = st.top();
            st.pop();
            if(temp->right)
                st.push(temp->right);
            if(temp->left)
                st.push(temp->left);
            if(!st.empty())
                temp->right = st.top();
            temp->left = NULL;
        }*/

        // optimal -> variation of morris traversal tc-o(n) sc-o(1)
        TreeNode *cur = root;
        while(cur!=NULL)
        {
            if(cur->left!=NULL)
            {
                TreeNode *prev = cur->left;
                while(prev->right!=NULL)
                    prev = prev->right;
                prev->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }
            cur = cur ->right;
        }
    }
};