/****************************************************************
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
For example, given
s = "leetcode",
dict = ["leet", "code"].
Return true because "leetcode" can be segmented as "leet code".
****************************************************************/
class Solution {
public:
    bool dfs(string &s, int p, unordered_set<string>& ws, vector<int> &f) {
        if (p == s.size()) return true;
        if (f[p] != -1) return f[p];
        for (auto it = ws.begin(); it != ws.end(); ++it) {
            if (s.find(*it, p) != p) continue;
            if (dfs(s, p + it->size(), ws, f)) {
                f[p] = 1;
                return true;
            }
        }
        f[p] = 0;
        return false;
    }
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.size();
        vector<int> f(n, -1);
        for (auto it = wordDict.begin(); it != wordDict.end(); ++it) {
            if (s.find(*it) != 0) continue;
            if (dfs(s, it->size(), wordDict, f)) return true;
        }
        return false;
    }
};