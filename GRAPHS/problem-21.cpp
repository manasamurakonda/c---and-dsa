// GFG - Alien Dictionary
class Solution {
  public:
    bool dfs(char cur,unordered_map<char,vector<char>> &m,vector<bool> &pathvis,vector<bool> &visited,string &ans)
    {
        visited[cur-'a'] = true;
        pathvis[cur-'a'] = true;
        for(auto it : m[cur])
        {
            if(!visited[it-'a'])
            {
                if(dfs(it,m,pathvis,visited,ans))
                    return true;
            }
            else if(pathvis[it-'a'])
                return true;
        }
        pathvis[cur-'a'] = false;
        ans.push_back(cur);
        return false;
    }
    string findOrder(vector<string> &words) {
        // optimal -> topo sort + detecting cycle in directed graph using dfs tc-o(26+n+26+E) sc-o(26+E+26+26+26)
        unordered_map<char,vector<char>> m;
        int n = words.size();
        vector<bool> present(26, false);
        for(auto &w : words){
            for(char c : w)
                present[c - 'a'] = true;
        }
        for(int i=0;i<n-1;i++)
        {
            int s1 = words[i].size(),s2 = words[i+1].size();
            int x=0;
            while(x<s1 && x<s2)
            {
                if(words[i][x]!=words[i+1][x])
                    break;
                x++;
            }
            if(x==s2 && s1>s2)
                return "";
            if(x<s1 && x<s2)
            {
                m[words[i][x]].push_back(words[i+1][x]);
            }
        }
        vector<bool> pathvis(26,false);
        vector<bool> visited(26,false);
        string ans="";
        for(int i = 0;i<26;i++){
            if(present[i] && !visited[i])
            {
                if(dfs(i+'a',m,pathvis,visited,ans))
                    return "";
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};