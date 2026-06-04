// symmetric tree 
// leetcode - 101
class Solution {
public:
    bool preorder(TreeNode * root1,TreeNode *root2)
    {
        if(root1 == NULL || root2==NULL)
        {
            return root1==root2;
        }

        if(root1->val!=root2->val)
            return false;
        if(!preorder(root1->left,root2->right))
            return false;
        if(!preorder(root1->right,root2->left))
            return false;
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        // optimal1 -> depth first search tc-o(n) sc-o(n)
        /*if(root == NULL)
            return true;
        return preorder(root->left,root->right);*/

        // optimal2 -> breadth first search tc-o(n) sc-o(n)
        if(root == NULL)
            return true;
        queue<pair<TreeNode *,TreeNode *>> q;
        q.push({root->left,root->right});
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                TreeNode *temp1 = q.front().first;
                TreeNode *temp2 = q.front().second;
                q.pop();
                if(temp1==NULL ||temp2==NULL)
                {
                    if(temp1==NULL && temp2 == NULL)
                        continue;
                    return temp1==temp2;
                }
                if(temp1->val!=temp2->val)
                    return false;
                q.push({temp1->left,temp2->right});
                q.push({temp1->right,temp2->left});
            }
        }
        return true;
    }
};