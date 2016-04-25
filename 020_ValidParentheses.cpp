/****************************************************************
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
****************************************************************/
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
                continue;
            }
            if (st.empty()) return false;
            char c = st.top();
            if (c == '(' && s[i] == ')' || c == '[' && s[i] == ']' || c == '{' && s[i] == '}')
                st.pop();
            else
                return false;
        }
        if (!st.empty()) return false;
        return true;
    }
};