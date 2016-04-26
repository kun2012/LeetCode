/****************************************************************
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
For "(()", the longest valid parentheses substring is "()", which has length = 2.
Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
****************************************************************/
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(i);
            else {
                if (!st.empty() && s[st.top()] == '(') {
                    st.pop();
                    int tmp = st.empty() ? -1 : st.top();
                    ans = max(ans, i - tmp);
                } else {
                    st.push(i);
                }
            }
        }
        return ans;
    }
};