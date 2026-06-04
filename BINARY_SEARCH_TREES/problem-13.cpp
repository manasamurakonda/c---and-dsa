// Recover BST
// leetcode - 99
class Solution {
public:
    void inorder(TreeNode *root,vector<int> &ans)
    {
        if(root==NULL)
            return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    void inorder1(TreeNode *root,vector<int> &ans,int &ind)
    {
        if(root == NULL)
            return;
        inorder1(root->left,ans,ind);
        if(root->val!=ans[ind])
            root->val = ans[ind];
            ind++;
        inorder1(root->right,ans,ind);
    }
    void inorder2(TreeNode *root,TreeNode *&first,TreeNode *&second,TreeNode *&prev)
    {
        if(root == NULL)
            return;
        inorder2(root->left,first,second,prev);
        if(prev!=NULL)
        {
            if(prev->val>root->val && first==NULL)
            {
                first = prev;
                second = root;
            }
            else if(prev->val>root->val)
            {
                second = root;
            }
        }
        prev = root;
        inorder2(root->right,first,second,prev);
    }
    void recoverTree(TreeNode* root) {
        // brute -> tc-o(2n+nlogn) sc-o(2n)
        /*vector<int> ans;
        inorder(root,ans);
        sort(ans.begin(),ans.end());
        int ind = 0;
        inorder1(root,ans,ind);*/

        // optimal -> tc-o(n) sc-o(n) (use morris traversal to avoid recursive space)
        TreeNode *first = NULL,*second=NULL;
        TreeNode *prev = NULL;
        inorder2(root,first,second,prev);
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
};