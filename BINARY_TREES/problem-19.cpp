// minimum time taken to burn a binary tree (or) Amount of Time for Binary Tree to Be Infected
// leetcode - 2385
class Solution {
public:
    void compute(TreeNode *root,unordered_map<TreeNode *,TreeNode *> &m,unordered_map<TreeNode *,bool> &flag,int &ans)
    {
        queue<pair<TreeNode *,int>> q;
        q.push({root,0});
        flag[root] = true;
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                TreeNode *temp = q.front().first;
                int level = q.front().second;
                q.pop();
                ans = max(ans,level);
                if(m[temp]!=NULL && flag[m[temp]]==false)
                {
                    flag[m[temp]] = true;
                    q.push({m[temp],level+1});
                }
                if(temp->left!=NULL && flag[temp->left] == false)
                {
                    flag[temp->left] = true;
                    q.push({temp->left,level+1});
                }
                if(temp->right!=NULL && flag[temp->right]==false)
                {
                    flag[temp->right] = true;
                    q.push({temp->right,level+1});
                }
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        // optimal -> bfs tc-o(2n) + o(2logn) sc-o(3n)
        int ans = 0;
        queue<TreeNode *> q;
        unordered_map<TreeNode *,TreeNode *> m;
        unordered_map<TreeNode *,bool> flag;
        TreeNode *target = NULL;
        q.push(root);
        m[root] = NULL;
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                flag[temp] = false;
                if(temp->val == start)
                    target = temp;
                if(temp->left!=NULL){
                    m[temp->left] = temp;
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    m[temp->right] = temp;
                    q.push(temp->right);
                }
            }
        }
        compute(target,m,flag,ans);
        return ans;
    }
};