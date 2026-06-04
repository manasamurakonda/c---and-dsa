// iterative postorder traversal
// leetcode - 145
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        // brute -> using a stack and reversing ans tc-o(2n) sc-o(n)
        /*vector<int> ans;
        stack<TreeNode*> st;
        if(root == NULL)
            return ans;
        st.push(root);
        while(!st.empty())
        {
            TreeNode *temp = st.top();
            st.pop();
            ans.push_back(temp->val);
            if(temp->left!=NULL)
                st.push(temp->left);
            if(temp->right!=NULL)
                st.push(temp->right);
        }
        reverse(ans.begin(),ans.end());
        return ans;*/

        // optimal -> just using 1 stack (complex approach) tc-o(n) sc-o(n)
        vector<int> ans;
        stack<TreeNode *> st;
        if(root == NULL)
            return ans;
        TreeNode *curr = root;
        while(curr!=NULL || !st.empty())
        {
            if(curr!=NULL)
            {
                st.push(curr);
                curr = curr->left;
            }
            else{
                TreeNode *temp = st.top()->right;
                if(temp == NULL)
                {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    while(!st.empty() && st.top()->right==temp)
                    {
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }
                else curr = temp;
            }
        }
        return ans;
    }
};