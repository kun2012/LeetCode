/****************************************************************
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
(you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:
string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
****************************************************************/
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string ts = "";
        int m = numRows + numRows - 2;
        int n = s.size();
        for (int i = 0; i < numRows; i++) {
            int x = i;
            int y = m - i;
            while(x < n) {
                ts = ts + s[x];
                x += m;
                if (i == 0 || i == numRows - 1) continue;
                if (y >= n) continue;
                ts = ts + s[y];
                y += m;
            }
        }
        return ts;
    }
};