/****************************************************************
Implement regular expression matching with support for '.' and '*'.
'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).
The function prototype should be:
bool isMatch(const char *s, const char *p)
Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
****************************************************************/
class Solution {
public:
    bool match(char c1, char c2) {
        if (c1 == c2) return true;
        if (c2 == '.') return true;
        return false;
    }
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        s = "#" + s;
        p = "#" + p;
        vector<vector<bool> > f(n + 1, vector<bool>(m + 1, false));
        f[0][0] = true;
        
        for (int i = 2; i <= m; i += 2) {
            f[0][i] = (p[i] == '*');
            if (!f[0][i]) break;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j] == '*') {
                    f[i][j] = f[i][j - 2];
                    if (f[i][j]) continue;
                    for (int k = i; k >= 1; k--) {
                        if (!match(s[k], p[j - 1])) break;
                        f[i][j] = f[k - 1][j - 2];
                        if (f[i][j]) break;
                    }
                } else {
                    f[i][j] = f[i - 1][j - 1] && match(s[i], p[j]);
                }
            }
        }
        return f[n][m];
    }
};