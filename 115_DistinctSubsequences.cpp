/****************************************************************
Given a string S and a string T, count the number of distinct subsequences of T in S.
A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
Here is an example:
S = "rabbbit", T = "rabbit"
Return 3.
****************************************************************/
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (n == 0 || m == 0) return 0;
        if (n < m) return 0;
        vector<vector<int> > f(n, vector<int>(m, 0));
        if (s[0] == t[0]) f[0][0] = 1;
        for (int i = 1; i < n; i++) {
            f[i][0] = f[i - 1][0] + (s[i] == t[0]);
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                f[i][j] = f[i - 1][j];
                if (s[i] == t[j]) f[i][j] += f[i - 1][j - 1];
            }
        }
        return f[n - 1][m - 1];
    }
};