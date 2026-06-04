// word ladder 2
// leetcode - 126
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // brute
       int n = wordList.size();
        unordered_map<string,int> m1;
        for(int i=0;i<n;i++)
        {
            m1[wordList[i]]++;
        }
        queue<vector<string>> q;
        bool flag = false;
        q.push({beginWord});
        m1.erase(beginWord);
        int sz = beginWord.size();
        while(!q.empty() && !flag)
        {
            int num = q.size();
            vector<string> pres;
            while(num){
                vector<string> temp = q.front();
                string cur = temp.back();
                q.pop();
                for(int i=0;i<sz;i++)
                {
                    string tp = cur;
                    for(char j='a';j<='z';j++)
                    {
                        if(j == cur[i]) continue;
                        vector<string> newPath = temp;
                        tp[i] = j;
                        if(tp == endWord && m1.find(tp)!=m1.end())
                            flag = true;
                        if(m1.find(tp)!=m1.end())
                        {
                            newPath.push_back(tp);
                            pres.push_back(tp);
                            q.push(newPath);
                        }
                    }
                }
                num--;
            }
            for(auto it : pres){
                m1.erase(it);
            }
        }
        vector<vector<string>> ans;
        while(!q.empty())
        {
            if(q.front().back()==endWord)
                ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};