// GFG - Root to Leaf Paths
class Solution {
  public:
    void preorder(Node *root,vector<vector<int>> &ans,vector<int> &temp)
    {
        if(root == NULL)
            return;
        temp.push_back(root->data);
        preorder(root->left,ans,temp);
        preorder(root->right,ans,temp);
        if(root->left==NULL && root->right==NULL)
            ans.push_back(temp);
        temp.pop_back();
    }
    vector<vector<int>> Paths(Node* root) {
        // optimal ->just pick and leave concept of recursion tc-o(n) sc-o(n)
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        vector<int> temp;
        preorder(root,ans,temp);
        return ans;
    }
};