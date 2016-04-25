/****************************************************************
Given a string, find the length of the longest substring without repeating characters.
Examples:
Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.
Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
****************************************************************/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0) return 0;
        vector<bool> vis(256, 0);
        int lo = 0, hi = 0, cnt = 0, ans = 0;
        while(hi < n) {
            char c = s[hi];
            if (vis[c]) {
                while(true) {
                    char x = s[lo];
                    vis[x] = false;
                    lo++;
                    cnt--;
                    if (x == c) break;
                }
            }
            vis[c] = true;
            cnt++;
            ans = max(ans, cnt);
            hi++;
        }
        return ans;
    }
};