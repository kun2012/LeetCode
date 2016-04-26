/****************************************************************
Validate if a given string is numeric.
Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous.
You should gather all requirements up front before implementing one.
****************************************************************/
// isdigit(<cctype>) : Check if character is decimal digit
class Solution {
public:
    bool isNumber(string s) {
        int n = s.size(), i = 0;
        while(i < n && s[i] == ' ') i++;
        if (i < n && (s[i] == '+' || s[i] == '-')) i++;
        bool is_num = false;
        while(i < n && isdigit(s[i])) {
            i++;
            is_num = true;
        }
        if (i < n && s[i] == '.') {
            i++;
            while(i < n && isdigit(s[i])) {
                i++;
                is_num = true;
            }
        }
        if(i < n && s[i] == 'e' && is_num) {
            i++;
            is_num = false;
            if (i < n && (s[i] == '+' || s[i] == '-')) i++;
            while(i < n && isdigit(s[i])) {
                i++;
                is_num = true;
            }
        }
        while (i < n && s[i] == ' ') i++;
        return is_num && i == n;
    }
};