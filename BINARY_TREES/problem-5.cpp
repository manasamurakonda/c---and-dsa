// maximum path sum of binary tree
// leetcode - 124
class Solution {
public:
    int maxpath(TreeNode *root,int &ans)
    {
        if(root == NULL)
            return 0;
        int ls = maxpath(root->left,ans);
        int rs = maxpath(root->right,ans);
        ans = max(ans,root->val+ls+rs);
        return max(0,root->val+max(ls,rs));
    }
    int maxPathSum(TreeNode* root) {
        // brute -> try path sums from every node to every node tc-o(n^2) sc-o(n^2)
        // optimal -> height of binary tree algorithm modification tc-o(n) sc-o(n)
        int ans = INT_MIN;
        maxpath(root,ans);
        return ans;
    }
};