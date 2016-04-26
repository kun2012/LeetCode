/****************************************************************
Given two numbers represented as strings, return multiplication of the numbers as a string.
Note:
The numbers can be arbitrarily large and are non-negative.
Converting the input string to integer is NOT allowed.
You should NOT use internal library such as BigInteger.
****************************************************************/
class Solution {
public:
    string multiply(string num1, string num2) {
        string s(num1.size() + num2.size(), '0');
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        for(int i = 0; i < num1.size(); i++) {   
            for(int j = 0; j < num2.size(); j++) {
                int c = (num1[i] - '0') * (num2[j] - '0') + s[i + j] - '0';
                s[i + j + 1] += c / 10;
                s[i + j] = c % 10 + '0';
            }
        }
        reverse(s.begin(),s.end());
        if (s.find_first_not_of('0') == string::npos)
            return "0";
        return s.substr(s.find_first_not_of('0'));
    }
};