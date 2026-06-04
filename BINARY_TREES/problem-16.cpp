// maximum width of binary tree
// leetcode - 662
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        // optimal -> val*2+1, val*2+2
        if(root==NULL)
            return 0;
        queue<pair<TreeNode *,long long>> q;
        q.push({root,1});
        long long ans=0;
        while(!q.empty())
            {
                int sz=q.size();
                long long maxi=0,mini=0;
                for(int i=0;i<sz;i++)
                    {
                        TreeNode *temp =q.front().first;
                        long long val=q.front().second;
                        if(i==0)
                            mini=val;
                        maxi=val;
                        q.pop();
                        if(temp->left!=NULL)
                        {
                            q.push({temp->left,(long long)(val-(long long)mini)*(long long)2+(long long)1});
                        }
                        if(temp->right!=NULL)
                        {
                            q.push({temp->right,((long long)(val-(long long)mini)*(long long)2)+(long long)2});
                        }
                    }
                ans=max(ans,maxi-mini+(long long)1);
            }
        return ans;
    }
};