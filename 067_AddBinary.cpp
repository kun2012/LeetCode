/****************************************************************
Given two binary strings, return their sum (also a binary string).
For example,
a = "11"
b = "1"
Return "100".
****************************************************************/
class Solution {
public:
    string addBinary(string a, string b) {
        int c = 0;
        int len = max(a.size(), b.size());
        string s = "";
        for (int i = 0; i < len; i++) {
            if (i < a.size())
                c += a[a.size() - i - 1] - '0';
            if (i < b.size())
                c += b[b.size() - 1 - i] - '0';
            if (c <= 1) {
                s = char(c + '0') + s;
                c = 0;
            }else {
                s = char(c - 2 + '0') + s;
                c = 1;
            }
        }
        if(c > 0) {
            s = char(c + '0') + s;
        }
        return s;
    }
};