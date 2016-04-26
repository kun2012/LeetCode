/****************************************************************
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.
Return all such possible sentences.
For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].
A solution is ["cats and dog", "cat sand dog"].
****************************************************************/
class Solution {
public:
    vector<string> dfs(string &s, size_t p, unordered_set<string> &ws, vector<int> &f, vector<vector<string> > &res) {
        if (p == s.size()) {
            vector<string> tmp(1, "");
            return tmp;
        }
        if (f[p] != -1) return res[p];
        for (auto it = ws.begin(); it != ws.end(); ++it) {
            if (s.find(*it, p) != p) continue;
            vector<string> tmp = dfs(s, p + it->size(), ws, f, res);
            if (tmp.size() != 0) {
                f[p] = 1;
                for (int j = 0; j < tmp.size(); j++)
                    res[p].push_back(" " + *it + tmp[j]);
            }
        }
        if (f[p] == -1) f[p] = 0;
        return res[p];
    }
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<int> f(s.size(), -1);
        vector<vector<string> > res(s.size());
        
        for (auto it = wordDict.begin(); it != wordDict.end(); ++it) {
            if (s.find(*it) != 0) continue;
            vector<string> tmp = dfs(s, it->size(), wordDict, f, res);
            for (int j = 0; j < tmp.size(); j++) {
                res[0].push_back(*it + tmp[j]);
            }
        } 
        return res[0];
    }
};