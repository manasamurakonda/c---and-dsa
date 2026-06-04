// maximum depth of binary tree
// leetcode - 104
class Solution {
public:
    int maxDepth(TreeNode* root) {
        //better -> level order traversal tc-o(n) sc-o(n)
        /*int ans = 0;
        queue<pair<TreeNode *,int>> q;
        if(root == NULL)
            return 0;
        q.push({root,1});
        ans++;
        while(!q.empty())
        {
            TreeNode *temp = q.front().first;
            int level = q.front().second;
            q.pop();
            if(temp->left!=NULL)
            {
                q.push({temp->left,level+1});
                ans= level+1;
            }
            if(temp->right!=NULL)
            {
                q.push({temp->right,level+1});
                ans = level+1;
            }
        }
        return ans;*/

        // optimal ->recursion tc-o(n) sc-o(n)
        if(root == NULL)
            return 0;

        int x= maxDepth(root->left);
        int y=maxDepth(root->right);
        return 1+max(x,y);
    }
};