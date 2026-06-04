// count complete tree nodes
// leetcode - 222
class Solution {
public:
    int height_left(TreeNode *root)
    {
        int cnt = 0;
        while(root!=NULL)
        {
            cnt++;
            root = root->left;
        }
        return cnt;
    }
    int height_right(TreeNode *root)
    {
        int cnt = 0;
        while(root!=NULL)
        {
            cnt++;
            root = root->right;
        }
        return cnt;
    }
    int countNodes(TreeNode* root) {
        // brute -> traversal tc-o(n) sc-o(n)
        /*if(root == NULL)    
            return 0;
        int x = countNodes(root->left);
        int y = countNodes(root->right);
        return 1+x+y;*/

        // optimal -> height of left and right tc-o(logn*logn) sc-o(logn)
        if(root == NULL)
            return 0;
        int x = height_left(root->left);
        int y = height_right(root->right);
        if(x==y)
            return (1<<(x+1))-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};