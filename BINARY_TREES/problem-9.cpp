// vertical order traversal of binary tree
// leetcode - 987
class Solution {
public:
    static bool comp(pair<pair<int,int>,int> &x,pair<pair<int,int>,int> &y)
    {
        if((x.first.first < y.first.first) ||
(x.first.first == y.first.first && x.first.second < y.first.second) ||
(x.first.first == y.first.first && x.first.second == y.first.second &&
 x.second < y.second))
            return true;
        return false;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // optimal -> giving vertical values and sorting tc-o(nlogn) sc- o(n)
        vector<vector<int>> ans;
        vector<pair<pair<int,int>,int>> temp;
        queue<pair<pair<int,int>,TreeNode *>> q;
        q.push({{0,0},root});
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                int vert = q.front().first.first;
                int level = q.front().first.second;
                TreeNode *cur = q.front().second;
                q.pop();
                temp.push_back({{vert,level},cur->val});
                if(cur->left!=NULL)
                    q.push({{vert-1,level+1},cur->left});
                if(cur->right!=NULL)
                    q.push({{vert+1,level+1},cur->right});
            }
        }
        sort(temp.begin(),temp.end(),comp);
        int vert = temp[0].first.first;
        for(int i=0;i<temp.size();i++)
        {
            vector<int> x;
            while(i<temp.size() && vert == temp[i].first.first)
            {
                x.push_back(temp[i].second);
                i++;
            }
            if(i<temp.size())
                vert = temp[i].first.first;
            i--;
            ans.push_back(x);
        }
        return ans;
    }
};