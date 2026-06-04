// GFG - Children Sum in a Binary Tree
class Solution {
  public:
    bool isSumProperty(Node *root) {
        // optimal-> basic DFS
        // learn the approach to convert the binary tree to follow children sum property
        if(root == NULL || (root->left==NULL && root->right==NULL))
            return true;
        int x = (root->left)? root->left->data: 0;
        int y = (root->right)? root->right->data: 0;
        if(x+y!=root->data)
            return false;
        if(!isSumProperty(root->left))
            return false;
        if(!isSumProperty(root->right))
            return false;
        return true;
    }
};
