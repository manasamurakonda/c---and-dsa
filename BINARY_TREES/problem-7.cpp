// zig zag traversal of a binary tree
// leetcode - 103
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // optimal -> store them in reverse order for some levels tc-o(n) sc-o(n)
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;
        while(!q.empty())
        {
            int size = q.size();
            vector<int> x(size);
            for(int i=0;i<size;i++){
                TreeNode *curr = q.front();
                int index=i;
                if(flag==false)
                    index = size-i-1;
                x[index] = curr->val;
                q.pop();
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
            }
            flag = !flag;
            ans.push_back(x);
        }
        return ans;
    }
};