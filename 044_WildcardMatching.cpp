/****************************************************************
Implement wildcard pattern matching with support for '?' and '*'.
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).
The function prototype should be:
bool isMatch(const char *s, const char *p)
Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
****************************************************************/
class Solution { //greedy : 匹配失败要回溯时只需要回去上一个*,之前的*不需要回溯
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        int lastp = -1, lasts = -1;
        int i = 0, j = 0;
        while(i < n) {
            if (s[i] == p[j] || p[j] == '?') {
                i++, j++;
            } else if (p[j] == '*') {
                ++j;
                lastp = j;
                lasts = i;
            } else if (lastp != -1) {
                j = lastp;
                i = (++lasts);
            } else {
                return false;
            }
        }
        while(j < m && p[j] == '*') j++;
        return j == m;
    }
};
/* DP 超时
class Solution {
public:
    bool match(char c1, char c2) {
        if (c1 == c2) return true;
        if (c2 == '?') return true;
        return false;
    }
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        s = "#" + s;
        p = "#" + p;
        vector<vector<bool> > f(n + 1, vector<bool>(m + 1, false));
        f[0][0] = true;
        
        for (int i = 1 ; i <= m; i++) {
            f[0][i] = (p[i] == '*');
            if (!f[0][i]) break;
        }
        
        for (int i = 1; i <= n; i++) {
            bool flag = false;
            for (int j = 1; j <= m; j++) {
                if (p[j] == '*') {
                    f[i][j] = flag;
                } else {
                    f[i][j] = f[i - 1][j - 1] && match(s[i], p[j]);
                }
                if (f[i][j]) flag = true;
            }
        }
        return f[n][m];
    }
};*/