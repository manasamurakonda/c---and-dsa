// GFG - Floor in BST
class Solution {
  public:
    int floor(Node* root, int x) {
        // optimal -> binary search tc-o(logn) sc-o(1)
        int ans = -1;
        while(root!=NULL)
        {
            if(root->data<=x)
            {
                ans = root->data;
                root = root->right;
            }
            else root = root->left;
        }
        return ans;
    }
};