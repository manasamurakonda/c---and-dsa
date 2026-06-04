// serialize and deserialize binary tree
// leetcode - 297
// tc-o(n) sc-o(n)
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode *> q;
        string data = "";
        if(root == NULL)
            return "#,";
        q.push(root);
        data = data + to_string(root->val);
        data.push_back(',');
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                if(temp->left!=NULL){
                    data = data + to_string(temp->left->val);
                    q.push(temp->left);
                }
                else data.push_back('#');
                data.push_back(',');
                if(temp->right!=NULL){
                    data = data + to_string(temp->right->val);
                    q.push(temp->right);
                }
                else data.push_back('#');
                data.push_back(',');
            }
        }
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "#,")
            return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode *> q;
        q.push(root);
        getline(s,str,',');
        while(!q.empty() && str!="")
        {
                TreeNode *temp = q.front();
                q.pop();
                if(str=="#")
                {
                    temp->left = NULL;
                }
                else{
                    temp->left = new TreeNode(stoi(str));
                    q.push(temp->left);
                }
                getline(s,str,',');
                if(str=="")
                    break;
                if(str=="#")
                {
                    temp->right = NULL;
                }
                else{
                    temp->right = new TreeNode(stoi(str));
                    q.push(temp->right);
                }
            getline(s,str,',');
        }
        return root;
    }
};