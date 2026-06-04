// binary search iterator
// leetcode - 173
class BSTIterator {
public: 
    // brute -> use a vector to store data tc-o(1) sc-o(n)
    /*int ind;
    vector<int> in;
    BSTIterator(TreeNode* root) {
        inorder(root,in);
        ind = -1;
    }
    void inorder(TreeNode *root,vector<int> &in)
    {
        if(root == NULL)
            return;
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
    int next() {
        ind++;
        return in[ind];
    }
    
    bool hasNext() {
        return ind+1<in.size();
    }*/
   // optimal -> use stack tc-o(1 approx) sc-o(height)
    stack<TreeNode *> st;
    BSTIterator(TreeNode* root) {
        while(root!=NULL)
        {
            st.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode *cur = st.top();
        st.pop();
        TreeNode *temp = cur->right;
        while(temp!=NULL)
        {
            st.push(temp);
            temp = temp->left;
        }
        return cur->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};