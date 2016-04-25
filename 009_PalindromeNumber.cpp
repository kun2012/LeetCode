/****************************************************************
Determine whether an integer is a palindrome. Do this without extra space.
Some hints:
Could negative integers be palindromes? (ie, -1)
If you are thinking of converting the integer to string, note the restriction of using extra space.
You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?
There is a more generic way of solving this problem.
****************************************************************/
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;
        int d = 1, t = x, cnt = 0;
        while(t > 0) {
            cnt++;
            t /= 10;
            if (t > 0) d *= 10;
        }
        while(true) {
            if (x % 10 != x / d) return false;
            x = (x - (x / d) * d) / 10;
            d = d / 100;
            if (d <= 1) break;
        }
        return true;
    }
};