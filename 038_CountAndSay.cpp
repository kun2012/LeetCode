/****************************************************************
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.
Note: The sequence of integers will be represented as a string.
****************************************************************/
class Solution {
public:
    string change(string &s) {
        if (s.size() == 1) return "1" + s;
        string res = "";
        int cnt = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) cnt++;
            else {
                res = res + char(cnt + '0') + s[i - 1];
                cnt = 1;
            }
            if (i == s.size() - 1) {
                res = res + char(cnt + '0') + s[i];
            }
        }
        return res;
    }
    string countAndSay(int n) {
        if (n == 1) return "1";
        string res = "1";
        for (int i = 1; i < n; i++) {
            res = change(res);
        }
        return res;
    }
};