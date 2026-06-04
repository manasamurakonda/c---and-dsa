// lowest common ancestor of a binary tree
// leetcode - 236
class Solution {
public:
    int preorder(TreeNode *root,TreeNode *p,TreeNode *q,TreeNode *ans)
    {
        if(root == NULL)
            return 0;
        int cnt = 0;
        if(root==p || root ==q)
            cnt++;
        int x = preorder(root->left,p,q);
        int y = preorder(root->right,p,q);
        if(ans==NULL && cnt+x+y==2)
            ans = root;
        return cnt+x+y;
            
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // better -> find root to node path of both nodes and find lowest common ancestor tc-o(2n) sc-o(2n)

        // optimal -> just returning 1 when we find p or q tc-o(n) sc-o(n)
        TreeNode *ans = NULL;
        preorder(root,p,q,ans);
        return ans;
    }
};