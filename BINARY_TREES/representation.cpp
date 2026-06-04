#include<bits/stdc++.h>
using namespace std;


class Tree{
public:
    int data;
    Tree *left;
    Tree *right;
    Tree(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
void preorder(Tree *root,vector<int> &ans)
    {
        if(root==NULL)
            return;
        ans.push_back(root->data);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
int main()
{
    Tree *root =new Tree(1);
    root-> left = new Tree(2);
    root->right = new Tree(3);
    vector<int> ans;
    preorder(root,ans);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    return 0;
}