/****************************************************************
Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are +, -, *, /. Each operand may be an integer or another expression.
Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
****************************************************************/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int op1 = 0, op2 = 0;
        for (int i = 0; i < tokens.size(); i++) {
            string s = tokens[i];
            if (s.size() == 1 && (s[0] < '0' || s[0] > '9')) {
                 op2 = st.top();
                st.pop();
                op1 = st.top();
                st.pop();
                if (s[0] == '+') {
                    st.push(op1 + op2);
                } else if (s[0] == '-') {
                    st.push(op1 - op2);
                } else if (s[0] == '*') {
                    st.push(op1 * op2);
                } else if (s[0] == '/') {
                    st.push(op1 / op2);
                }
            } else {
                bool f = false;
                int x = 0;
                if (s[0] == '-') {
                    f = true;
                    x = 1;
                }
                op1 = 0;
                for (int j = x; j < s.size(); j++) {
                    op1 = op1 * 10 + s[j] - '0';
                }
                if(f) op1 = -op1;
                st.push(op1);
            }
        }
        return st.top();
    }
};