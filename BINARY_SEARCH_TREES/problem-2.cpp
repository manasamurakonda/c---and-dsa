// GFG - Ceil in BST
class Solution {
  public:
    int findCeil(Node* root, int x) {
        // optimal -> binary search tc-o(logn) sc-o(1)
        int ans = -1;
        while(root!=NULL)
        {
            if(root->data>=x)
            {
                ans = root->data;
                root = root->left;
            }
            else root = root->right;
        }
        return ans;
    }
};