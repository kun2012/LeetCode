/****************************************************************
Given a string s, partition s such that every substring of the partition is a palindrome.
Return all possible palindrome partitioning of s.
For example, given s = "aab",
Return
  [
    ["aa","b"],
    ["a","a","b"]
  ]
****************************************************************/
class Solution {
public:
    vector<vector<string>> res;
    void dfs(string &s, int p, vector<string> &cur, vector<vector<bool> > &g) {
        if (p == s.size()) {
            res.push_back(cur);
            return ;
        }
        for (int i = p; i < s.size(); i++) {
            if (!g[p][i]) continue;
            cur.push_back(s.substr(p, i - p + 1));
            dfs(s, i + 1, cur, g);
            cur.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool> > g(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++)
            g[i][i] = true;
        for (int k = 2; k <= n; k++) {
            for (int i = 0; i + k <= n; i++) {
                int j = i + k - 1;
                g[i][j] = (s[i] == s[j] && (i + 1 == j || g[i + 1][j - 1]));
            }
        }
        vector<string> cur;
        dfs(s, 0, cur, g);
        return res;
    }
};