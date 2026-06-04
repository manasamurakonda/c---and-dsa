// delete a node in BST
// leetcode - 450
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // optimal -> 3 cases of deletion tc-o(height of tree) sc-o(1)
        if(root == NULL)
            return NULL;
        TreeNode *temp = root;
        TreeNode *prev= NULL;
        while(temp!=NULL)
        {
            if(temp->val == key){
                break;
            }
            prev = temp;
            if(temp->val>key)
                temp = temp->left;
            else temp = temp->right;
        }
        if(temp==NULL)
            return root;
        if(temp->left==NULL && temp->right==NULL)
        {
            if(prev == NULL)
            {
                return NULL;
            }
            else{
                if(prev->left==temp)
                    prev->left = NULL;
                else prev->right=NULL;
            }
        }
        else if(temp->left ==NULL)
        {
            if(prev==NULL)
            {
                return temp->right;
            }
            else{
                if(prev->left==temp)
                    prev->left = temp->right;
                else prev->right = temp->right;
            }
        }
        else if(temp->right == NULL)
        {
            if(prev==NULL)
            {
                return temp->left;
            }
            else{
                if(prev->left==temp)
                    prev->left = temp->left;
                else prev->right = temp->left;
            }
        }
        else{
            TreeNode *pr = temp;
            TreeNode *x = temp->left;
            while(x->right!=NULL)
            {
                pr = x;
                x = x->right;
            }
            if(pr->left==x)
                pr->left=x->left;
            else pr->right = x->left;
            if(prev==NULL)
            {
                x->right = temp->right;
                x->left = temp->left;
                return x;
            }
            else{
                if(prev->left==temp)
                    prev->left = x;
                else prev->right = x;
                x->right = temp->right;
                x->left = temp->left;
            }
        }
        delete temp;
        return root;
    }
};