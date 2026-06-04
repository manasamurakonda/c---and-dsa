// kth smallest element in BST
// leecode - 230
class Solution {
public:
    void inorder(TreeNode *root,int &cnt,int &k,int &ans)
    {
        if(root == NULL)
            return;
        inorder(root->left,cnt,k,ans);
        cnt++;
        if(cnt==k)
            ans = root->val;
        inorder(root->right,cnt,k,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        // brute -> inorder traversal tc-o(n) sc-o(n)
        /*int ans = 0,cnt=0;
        inorder(root,cnt,k,ans);
        return ans;*/

        // optimal -> use morris inorder traversal tc-o(n) sc-o(1)
    }
};