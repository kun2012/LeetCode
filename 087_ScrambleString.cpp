/****************************************************************
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
Below is one possible representation of s1 = "great":
    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.
For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".
Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".
Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
****************************************************************/
class Solution {
public:
    bool cmp(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2;
    }
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        if (n == 1 && s1 == s2) return true;
        for (int i = 1; i < n; i++) {
            string ts1 = s1.substr(0, i);
            string ts2 = s2.substr(0, i);
            if (cmp(ts1, ts2)) {
                string ts3 = s1.substr(i);
                string ts4 = s2.substr(i);
                if (cmp(ts3, ts4)) {
                    if (isScramble(ts1, ts2) && isScramble(ts3, ts4)) return true;
                }
            }
            ts2 = s2.substr(n - i, i);
            if (cmp(ts1, ts2)) {
                string ts3 = s1.substr(i);
                string ts4 = s2.substr(0, n - i);
                if (cmp(ts3, ts4)) {
                    if (isScramble(ts1, ts2) && isScramble(ts3, ts4)) return true;
                }
            }
            
        }
        return false;
    }
};