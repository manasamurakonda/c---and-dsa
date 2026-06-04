// insert a node in binary search tree
// leetcode - 701
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // optimal -> insert at leaf place tc-o(logn) sc-o(1)
        TreeNode *root1 = root;
        TreeNode *temp = root;
        while(root!=NULL)
        {
            temp = root;
            if(val<root->val)
                root = root->left;
            else root = root->right;
        }
        if(temp==NULL)
            root1 = new TreeNode(val);
        else if(temp->val<val)
            temp->right = new TreeNode(val);
        else temp->left = new TreeNode(val);
        return root1;
    }
};