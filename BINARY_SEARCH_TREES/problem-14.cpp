// GFG - Largest BST
class Helper
{
public:
    int maxval;
    int minval;
    int maxsize;
    Helper(int max,int min,int sz)
    {
        maxval = max;
        minval = min;
        maxsize = sz;
    }
};
class Solution {
  public:
    Helper compute(Node *root)
    {
        if(root == NULL)
            return Helper(INT_MIN,INT_MAX,0);
        
        auto lt = compute(root->left);
        auto rt = compute(root->right);
        
        if(root->data>lt.maxval && root->data<rt.minval)
        {
            return Helper(max(root->data,rt.maxval),min(root->data,lt.minval),lt.maxsize+rt.maxsize+1);
        }
        
        return Helper(INT_MAX,INT_MIN,max(lt.maxsize,rt.maxsize));
    }
    int largestBst(Node *root) {
        // brute -> check for every subtree tc-o(n^2) sc-o(n)
        
        // optimal -> bottom up (postorder traversal) tc-o(n) sc-o(n)
        return compute(root).maxsize;
    }
};