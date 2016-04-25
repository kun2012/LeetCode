/****************************************************************
Given a roman numeral, convert it to an integer.
Input is guaranteed to be within the range from 1 to 3999.
****************************************************************/
class Solution {
public:
    int romanToInt(string s) {
        string sym[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        int ans = 0;
        int len = s.size();
        for (int i = 0, p = 0; p < len; i++) {
            while(len - p >= sym[i].size()) {
                bool ismatch = true;
                for (int j = 0; j < sym[i].size(); j++) {
                    if (sym[i][j] != s[p + j]) {
                        ismatch = false;
                        break;
                    }
                }
                if (ismatch) {
                    p += sym[i].size();
                    ans += val[i];
                } else {
                    break;
                }
            }
        }
        return ans;
    }
};