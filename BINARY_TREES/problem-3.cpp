// check for balanced binary tree
// leetcode - 110
class Solution {
public:
    int height(TreeNode *root,bool &ans)
    {
        if(root == NULL)    
            return 0;
        int x = height(root->left,ans);
        int y = height(root->right,ans);
        if(abs(x-y)>1)
            ans = false;
        return 1+max(x,y);
    }
    int height1(TreeNode *root)
    {
        if(root == NULL)    
            return 0;
        int x = height1(root->left);
        int y = height1(root->right);
        return 1+max(x,y);
    }
    bool isBalanced(TreeNode* root) {
        // brute -> check for every node tc-o(n^2) sc-o(n^2)
        /*if(root == NULL)
            return true;
        int lh = height1(root->left);
        int rh = height1(root->right);
        if(abs(lh-rh)>1)
            return false;
        if(isBalanced(root->left)==false)
            return false;
        if(isBalanced(root->right)==false)
            return false;
        return true;*/
        // optimal -> modifying algorithm for finding height of the tree tc-o(n) sc - o(n)
        bool ans = true;
        height(root,ans);
        return ans;
    }
};