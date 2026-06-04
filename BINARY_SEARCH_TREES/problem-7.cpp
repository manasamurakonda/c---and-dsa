// validate binary search tree
// leetcode - 98
class Solution {
public:
    bool inorder(TreeNode *root, TreeNode *&prev)
    {
        if(root == NULL)
            return true;
        if(inorder(root->left,prev)==false)
            return false;
        if(prev!=NULL && prev->val>=root->val)
            return false;
        prev = root;
        if(inorder(root->right,prev)==false)
            return false;
        return true;
    }
    bool preorder(TreeNode *root,long long mini,long long maxi)
    {
        if(root == NULL)
            return true;
        if(root->val>=maxi || root->val<=mini)
            return false;
        if(preorder(root->left,mini,root->val)==false)
            return false;
        if(preorder(root->right,root->val,maxi)==false)
            return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        // inorder traversal -> my approach tc-o(n) sc-o(n)
        /*TreeNode *prev = NULL;
        return inorder(root,prev);*/

        // strivers approach -> tc-o(n) sc-o(n)
        long long maxi = LLONG_MAX,mini = LLONG_MIN;
        return preorder(root,mini,maxi);
    }
};