/****************************************************************
Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.
For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
****************************************************************/
class Solution {
public:
    int dfs(string &s, int p, vector<int> &f, vector<vector<bool> > &g) {
        if (p == s.size()) return 0;
        if (f[p] != -1) return f[p];
        f[p] = INT_MAX;
        for (int i = p; i < s.size(); i++) {
            if (!g[p][i]) continue;
            f[p] = min(f[p], dfs(s, i + 1, f, g) + 1);
        }
        return f[p];
    }
    int minCut(string s) {
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
        vector<int> f(n, -1);
        return dfs(s, 0, f, g) - 1;
    }
};