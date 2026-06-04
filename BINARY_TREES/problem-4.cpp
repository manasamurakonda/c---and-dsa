// finding diameter of a binary tree
// leetcode - 543
class Solution {
public:
    int height(TreeNode *root,int &diameter)
    {
        if(root == NULL)
            return 0;
        int x = height(root->left,diameter);
        int y = height(root->right,diameter);
        diameter = max(diameter,x+y);
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
    void diameter(TreeNode *root,int &dia)
    {
        if(root == NULL)
            return;
        int lh = height1(root->left);
        int rh = height1(root->right);
        dia = max(dia,lh+rh);
        diameter(root->left,dia);
        diameter(root->right,dia);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        // brute -> finding diameter at each node tc-o(n^2) sc-o(n^2)
        /*int ans = 0;
        diameter(root,ans);
        return ans;*/
        // optimal -> modifying height of binary tree algorithm tc-o(n) sc-o(n) 
        int diameter = 0;
        height(root,diameter);
        return diameter;
    }
};