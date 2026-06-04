// GFG - Inorder Successor in BST
class Solution {
  public:
    void inorder(Node *root,bool &flag,int &ans)
    {
        if(root == NULL)
            return;
        inorder(root->left,flag,ans);
        if(flag && root->data>ans){
            ans = root->data;
            flag = false;
        }
        inorder(root->right,flag,ans);
    }
    int inOrderSuccessor(Node *root, Node *x) {
        // brute -> inorder traversal tc-o(n) sc-o(n)
        /*int ans = x->data;
        bool flag = true;
        inorder(root,flag,ans);
        if(ans==x->data)
            return -1;
        return ans;*/
        
        // optimal -> binary search tc-o(height) sc-o(1)
        Node *cur = root;
        int ans = -1;
        while(cur!=NULL)
        {
            if(cur->data>x->data)
            {
                ans = cur->data;
                cur = cur->left;
            }
            else cur = cur->right;
        }
        return ans;
    }
};