// search in a binary search tree
// leetcode - 700
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // brute -> linear search tc-o(n) sc-o(n)
        // optimal -> binary search tc-o(logn) sc -o(1)
        while(root!=NULL)
        {
            if(val==root->val)
                break;
            else if(val<root->val)
                root = root->left;
            else root = root->right;
        }
        return root;
    }
};