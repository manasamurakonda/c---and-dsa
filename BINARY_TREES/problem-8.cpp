// GFG - Tree Boundary Traversal
class Solution {
  public:
    bool isLeaf(Node *root)
    {
        if(root == NULL)
            return false;
        if(root->left==NULL && root->right==NULL)
            return true;
        return false;
    }
    void left_boundary(Node *root,vector<int> &ans)
    {
        Node *cur = root->left;
        while(cur!=NULL)
        {
            if(!isLeaf(cur))
                ans.push_back(cur->data);
            if(cur->left!=NULL)
                cur = cur ->left;
            else cur = cur->right;
        }
    }
    void right_boundary(Node *root,vector<int> &ans)
    {
        Node *cur = root->right;
        while(cur!=NULL)
        {
            if(!isLeaf(cur))
                ans.push_back(cur->data);
            if(cur->right!=NULL)
                cur = cur ->right;
            else cur = cur->left;
        }
        reverse(ans.begin(),ans.end());
    }
    void leaf_nodes(Node *root,vector<int> &ans)
    {
        if(root == NULL)
            return;
        leaf_nodes(root->left,ans);
        if(isLeaf(root))
            ans.push_back(root->data);
        leaf_nodes(root->right,ans);
    }
    vector<int> boundaryTraversal(Node *root) {
        //optimal ->(no recursion needed) find left boundary , leaf nodes, right boundary seperately tc-o(n) sc-o(n)
        vector<int> ans1,ans2,ans;
        if(root == NULL)
            return ans;
        if(!isLeaf(root))
            ans.push_back(root->data);
        left_boundary(root,ans);
        leaf_nodes(root,ans1);
        right_boundary(root,ans2);
        for(int i=0;i<ans1.size();i++)
            ans.push_back(ans1[i]);
        for(int i=0;i<ans2.size();i++)
            ans.push_back(ans2[i]);
        return ans;
    }
};