/****************************************************************
Given a digit string, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below.
1	   | 2 abc | 3 def
4 ghi  | 5 jkl | 6 mno
7 pqrs | 8 tuv | 9 wxyz
*+     | 0 _   | #

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
****************************************************************/
class Solution {
public:
    string get(char c) {
        switch(c) {
            case '2':
                return "abc";
            case '3':
                return "def";
            case '4':
                return "ghi";
            case '5':  
                return "jkl";  
            case '6':  
                return "mno";  
            case '7':  
                return "pqrs";  
            case '8':  
                return "tuv";  
            case '9':  
                return "wxyz";  
            case '0':  
                return " ";  
            default:  
                return "";
        }
    }
    void dfs(string &digits, int p, string s, vector<string> &vs) {
        if (p == digits.size()) {
            vs.push_back(s);
            return ;
        }
        string ts = get(digits[p]);
        for (int i = 0; i < ts.size(); i++) {
            dfs(digits, p + 1, s + ts[i], vs);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> vs;
        if (digits.size() > 0)
            dfs(digits, 0, "", vs);
        return vs;
    }
};