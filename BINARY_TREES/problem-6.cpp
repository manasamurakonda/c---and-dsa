// check if two trees are identical or not
// leetcode - 100
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // optimal -> use any traversal to check tc-o(n) sc-o(n)
        if(p==NULL && q==NULL)
            return true;
        if((p==NULL && q!=NULL) || (p!=NULL && q==NULL) || (p->val!=q->val))
                return false;
        if(!isSameTree(p->left,q->left))
            return false;
        if(!isSameTree(p->right,q->right))
            return false;
        return true;
    }
};