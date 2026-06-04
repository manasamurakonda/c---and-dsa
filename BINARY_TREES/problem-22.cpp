// construct binary tree from postorder and inorder traversal
// leetcode - 106
class Solution {
public:
    TreeNode* compute(vector<int>& inorder, vector<int>& postorder,int is,int ie,int ps,int pe,unordered_map<int,int> &m)
    {
        if(is>ie || ps>pe)
            return NULL;
        TreeNode *root = new TreeNode(postorder[ps]);
        int cnt = ie-m[postorder[ps]];
        root->right = compute(inorder,postorder,m[postorder[ps]]+1,ie,ps+1,ps+cnt,m);
        root->left = compute(inorder,postorder,is,m[postorder[ps]]-1,ps+cnt+1,pe,m);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // optimal -> tc-o(nlogn) sc-o(2n)
        int n = inorder.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
            m[inorder[i]]=i;
        reverse(postorder.begin(),postorder.end());
        return compute(inorder,postorder,0,n-1,0,n-1,m);
    }
};