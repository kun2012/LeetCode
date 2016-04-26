/****************************************************************
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
For example,
Given:
s1 = "aabcc",
s2 = "dbbca",
When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
****************************************************************/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), h = s3.size();
        if (n + m != h) return false;
        if (n == 0) {
            if (s2 == s3) return true;
            return false;
        }
        if (m == 0) {
            if (s1 == s3) return true;
            return false;
        }
        s1 = "#" + s1;
        s2 = "#" + s2;
        vector<vector<bool> > f(n + 1, vector<bool>(m + 1, false));
        f[0][0] = true;
        for (int i = 1; i <= n; i++) {
            f[i][0] = (f[i - 1][0] && (s1[i] == s3[i - 1]));
        }
        for (int i = 1; i <= m; i++) {
            f[0][i] = (f[0][i - 1] && (s2[i] == s3[i - 1]));
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i] == s3[i + j - 1] && f[i - 1][j]) {
                    f[i][j] = true;
                }
                if (s2[j] == s3[i + j - 1] && f[i][j - 1]) {
                    f[i][j] = true;
                }
            }
        }
        return f[n][m];
    }
};