// two sum in BST
// leetcode - 653
class Solution {
public:
    void inorder(TreeNode *root,vector<int> &arr)
    {
        if(root == NULL)
            return;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    bool findTarget(TreeNode* root, int k) {
        // brute -> store inorder traversal in an array and use two pointers tc-o(n+n/2) sc-o(2n)
        /*vector<int> arr;
        inorder(root,arr);
        int l = 0,r = arr.size()-1;
        while(l<r)
        {
            if(arr[l]+arr[r]==k)
                return true;
            else if(arr[l]+arr[r]<k)
                l++;
            else r--;
        }
        return false;*/
        
        // optimal -> binary search tree iterators tc-o(1 approx) sc-o(2*height)
        stack<TreeNode *> st1,st2;
        TreeNode *cur = root;
        while(cur!=NULL)
        {
            st1.push(cur);
            cur = cur->left;
        }
        cur = root;
        while(cur!=NULL)
        {
            st2.push(cur);
            cur = cur -> right;
        }
        while(!st1.empty() && !st2.empty() && st1.top()!=st2.top())
        {
            if(st1.top()->val+st2.top()->val==k)
                return true;
            else if(st1.top()->val+st2.top()->val<k)
            {
                TreeNode *temp = st1.top();
                st1.pop();
                cur = temp->right;
                while(cur!=NULL)
                {
                    st1.push(cur);
                    cur = cur->left;
                }
            }
            else{
                TreeNode *temp = st2.top();
                st2.pop();
                cur = temp->left;
                while(cur!=NULL)
                {
                    st2.push(cur);
                    cur = cur->right;
                }
            }
        }
        return false;
    }
};