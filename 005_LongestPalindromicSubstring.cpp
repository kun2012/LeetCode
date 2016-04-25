/****************************************************************
Given a string S, find the longest palindromic substring in S. 
You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
****************************************************************/
class Solution {
public:
    string longestPalindrome(string s) {
        string ts = "#";
        for (int i = 0; i < s.size(); i++) {
            ts = ts + s[i] + "#";
        }
        int n = ts.size(), ans = 0;
        vector<int> p(n, 0);
        int maxlen = 0, idx = 0;
        for (int i = 1; i < n; i++) {
            p[i] = (maxlen > i ? min(p[idx + idx - i], maxlen - i) : 0);
            while(i - p[i] - 1 >= 0 && i + p[i] + 1 < n && ts[i - p[i] - 1] == ts[i + p[i] + 1])
                p[i]++;
            if (i + p[i] > maxlen) {
                maxlen = i + p[i];
                idx = i;
            }
            if (p[i] > p[ans]) {
                ans = i;
            }
        }
        return s.substr((ans - p[ans]) / 2, p[ans]);
    }
};