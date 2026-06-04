// construct binary search tree from preorder traversal
// leetcode - 1008
class Solution {
public:
    void compute(int &ind,TreeNode *root,vector<int>& preorder)
    {
        int num = preorder[ind];
        TreeNode *cur = root,*prev = NULL;
        while(cur!=NULL)
        {
            prev = cur;
            if(num<cur->val)
                cur = cur->left;
            else cur = cur->right;
        }
        if(num<prev->val)
        {
            prev->left = new TreeNode(num);
            return;
        }
        prev->right = new TreeNode(num);
    }
    TreeNode* compute1(vector<int>& preorder,int &ind,int mini,int maxi)
    {
        if(ind==preorder.size() || preorder[ind]<=mini || preorder[ind]>=maxi)
            return NULL;
        TreeNode *root = new TreeNode(preorder[ind]);
        ind++;
        root->left = compute1(preorder,ind,mini,root->val);
        root->right = compute1(preorder,ind,root->val,maxi);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // brute -> checking where every value of preorder fits tc-o(n^2) sc-o(1)
        /*TreeNode *root = new TreeNode(preorder[0]);
        int n = preorder.size();
        for(int i=1;i<n;i++)
        {
            compute(i,root,preorder);
        }
        return root;*/

        // better -> sort the preorder and you will get inorder and you can build a BT using in and preorders tc-o(nlogn+n) sc-o(n)

        // optimal -> based on minimum and maximum range of a place can be tc-o(n) sc-o(n)
        int ind = 0;
        return compute1(preorder,ind,INT_MIN,INT_MAX);
    }
};