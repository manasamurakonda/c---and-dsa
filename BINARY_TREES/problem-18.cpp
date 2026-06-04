// All Nodes Distance K in Binary Tree
// leetcode-863
class Solution {
public:
    void compute(TreeNode* root,int &k,unordered_map<TreeNode *,TreeNode *> &m,unordered_map<TreeNode *,bool> &flag, vector<int> &ans)
    {
        queue<pair<TreeNode *,int>> q;
        q.push({root,0});
        flag[root] = true;
        while(!q.empty())
        {
            int sz = q.size();
            if(q.front().second == k+1)
                break;
            for(int i=0;i<sz;i++)
            {
                TreeNode *temp = q.front().first;
                int level = q.front().second;
                q.pop();
                if(level == k)
                    ans.push_back(temp->val);
                if(m[temp]!=NULL && flag[m[temp]]==false){
                    flag[m[temp]] = true;
                    q.push({m[temp],level+1});
                }
                if(temp->left!=NULL && flag[temp->left]==false){
                    flag[temp->left] = true;
                    q.push({temp->left,level+1});
                }
                if(temp->right!=NULL && flag[temp->right]==false){
                    flag[temp->right] = true;
                    q.push({temp->right,level+1});
                }
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // optimal ->bfs tc-o(2n)+o(2logn) sc-o(3n)
        vector<int> ans;
        unordered_map<TreeNode *,TreeNode *> m;
        unordered_map<TreeNode *,bool> flag;
        m[root] = NULL;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                flag[temp] = false;
                if(temp->left!=NULL)
                {
                    m[temp->left] = temp;
                    q.push(temp->left);
                }
                if(temp->right!=NULL)
                {
                    m[temp->right] = temp;
                    q.push(temp->right);
                }
            }
        }
        compute(target,k,m,flag,ans);
        return ans;
    }
};