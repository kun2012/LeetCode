/****************************************************************
Implement atoi to convert a string to an integer.
Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
****************************************************************/
//A C++ way to trim string
class Solution {
public:
    int myAtoi(string str) {
        int a = 0x7fffffff;
        int b = 0x80000000;
        long ans = 0;
        str.erase(str.begin(), find_if(str.begin(), str.end(), not1(ptr_fun<int, int>(isspace))));
        str.erase(find_if(str.rbegin(), str.rend(), not1(ptr_fun<int, int>(std::isspace))).base(), str.end());
        
        if (str.size() == 0) return 0;
        int sign = 1;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '-') {
                if (i != 0) return 0;
                sign = -1;
                continue;
            }
            if (str[i] == '+') {
                if (i != 0) return 0;
                sign = 1;
                continue;
            }
            if (str[i] < '0' || str[i] > '9')
                break;
            ans = ans * 10 + str[i] - '0';
            if (sign * ans > a) {
                return a;
            }
            if ( sign * ans < b) {
                return b;
            }
        }
        return sign * (int)ans;
    }
};