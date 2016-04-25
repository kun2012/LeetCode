/****************************************************************
Reverse digits of an integer.
Example1: x = 123, return 321
Example2: x = -123, return -321

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
Did you notice that the reversed integer might overflow? 
Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. 
Assume that your function returns 0 when the reversed integer overflows.
****************************************************************/
class Solution {
public:
    int reverse(int x) {
        bool is_negative = false;
        if (x < 0) {
            is_negative = true;
            x = -x;
        }
        int a = 0x7fffffff;
        int b = 0x80000000;
        long rev = 0;
        while(x > 0) {
            int c = x % 10;
            rev = rev * 10 + (long)c;
            if (rev > a || rev < b) {
                return 0;
            }
            x = x / 10;
        }
        if (is_negative) rev = -rev;
        return (int)rev;
    }
};