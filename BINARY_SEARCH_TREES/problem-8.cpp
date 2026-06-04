// lca in BST
// leetcode - 235
class Solution {
public:
    int lca(TreeNode *root,TreeNode *p,TreeNode *q,TreeNode *&ans)
    {
        if(root == NULL)
            return 0;
        int cnt = 0;
        if(root == p || root == q)
            cnt++;
        int x = lca(root->left,p,q,ans);
        int y = lca(root->right,p,q,ans);
        if(ans == NULL && cnt+x+y == 2)
            ans = root;
        return cnt+x+y;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // brute -> normal lca tc-o(n) sc-o(n)
        /*TreeNode *ans = NULL;
        lca(root,p,q,ans);
        return ans;*/

        //optimal -> binary search tc-o(logn) sc-o(1)
        TreeNode * cur = root;
        while(cur!=NULL){
            if(cur->val<p->val && cur->val<q->val)
                cur = cur->right;
            else if(cur->val>p->val && cur->val>q->val)
                cur = cur->left;
            else return cur;
        }
        return cur;
    }
};