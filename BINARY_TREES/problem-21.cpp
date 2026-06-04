// construct binary tree from preorder and inorder traversal
// leetcode - 105
class Solution {
public:
    TreeNode* compute(vector<int> &preorder,int pstart,int pend,vector<int> &inorder,int instart,int inend,unordered_map<int,int> &m)
    {
        if(pstart>pend || instart>inend)
            return NULL;
        TreeNode *root = new TreeNode(preorder[pstart]);
        int cur = m[preorder[pstart]];
        int res = cur-instart;
        root->left = compute(preorder,pstart+1,pstart+res,inorder,instart,cur-1,m);
        root->right = compute(preorder,pstart+res+1,pend,inorder,cur+1,inend,m);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // optimal -> tc-o(nlogn) sc-o(2n)
        unordered_map<int,int> m;
        for(int i=0;i<inorder.size();i++)
            m[inorder[i]]=i;
        return compute(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,m);
    }
};