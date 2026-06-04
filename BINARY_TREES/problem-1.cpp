// 3 traversals in one traversal
// coding ninjas
// tc-o(3n) sc-o(n)
vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector<int> inorder;
    vector<int> preorder;
    vector<int> postorder;
    stack<pair<TreeNode *,int>> st;
    if(root == NULL)
        return {inorder,preorder,postorder};
    st.push({root,1});
    while(!st.empty())
    {
        TreeNode *temp = st.top().first;
        int num = st.top().second;
        st.pop();
        if(num==1)
        {
            preorder.push_back(temp->data);
            st.push({temp,2});
            if(temp->left!=NULL)
                st.push({temp->left,1});
        }
        else if(num == 2)
        {
            inorder.push_back(temp->data);
            st.push({temp,3});
            if(temp->right!=NULL)
                st.push({temp->right,1});
        }
        else{
            postorder.push_back(temp->data);
        }
    }
    return {inorder,preorder,postorder};
}