/****************************************************************
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
You have the following 3 operations permitted on a word:
a) Insert a character
b) Delete a character
c) Replace a character
****************************************************************/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        string s1 = "#" + word1;
        string s2 = "#" + word2;
        vector<vector<int> > f(n + 1, vector<int>(m + 1, 100000000));
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            f[i][0] = i;
        }
        for (int i = 1; i <= m; i++) {
            f[0][i] = i;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
                if (s1[i] == s2[j]) f[i][j] = min(f[i][j], f[i - 1][j - 1]);
                else f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
            }
        }
        return f[n][m];
    }
};