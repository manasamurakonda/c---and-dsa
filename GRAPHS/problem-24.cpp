// word ladder
// leetcode - 127
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // optimal -> breadth first search tc-o(n*len(beginWord)*26) sc-o(3n)
        int n = wordList.size();
        unordered_map<string,int> m;
        unordered_map<string,int> m1;
        for(int i=0;i<n;i++)
        {
            m1[wordList[i]]++;
        }
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        int sz = beginWord.size();
        while(!q.empty())
        {
            string cur = q.front().first;
            int dist = q.front().second;
            q.pop();
            for(int i=0;i<sz;i++)
            {
                string temp = cur;
                for(char j='a';j<='z';j++)
                {
                    temp[i] = j;
                    if(temp == endWord && m1.find(temp)!=m1.end())
                        return dist+1;
                    if(m.find(temp)==m.end() && m1.find(temp)!=m.end())
                    {
                        m[temp]++;
                        q.push({temp,dist+1});
                    }
                }
            }
        }
        return 0;
    }
};