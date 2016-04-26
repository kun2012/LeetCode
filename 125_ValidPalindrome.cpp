/****************************************************************
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.
Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.
For the purpose of this problem, we define empty string as valid palindrome.
****************************************************************/
class Solution {
public:
    bool ok(char c) {
        if (c >= '0' && c <= '9' || c >= 'a' &&  c <= 'z' || c >= 'A' && c <= 'Z')
            return true;
        return false;
    }
    char low(char c) {
        if (c >= 'A' && c <='Z') return char(c + 32);
        return c;
    }
    bool isPalindrome(string s) {
        if (s == "") return true;
        int i = 0, j = s.size() - 1;
        while(true) {
            while(i <= j && !ok(s[i])) i++;
            if (i > j) return true;
            while(i <= j && !ok(s[j])) j--;
            if (i == j) return true;
            if (low(s[i]) != low(s[j])) return false;
            i++;
            j--;
        }
    }
};