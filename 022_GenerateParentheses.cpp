/****************************************************************
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
For example, given n = 3, a solution set is:
"((()))", "(()())", "(())()", "()(())", "()()()"
****************************************************************/
class Solution {
public:
    void dfs(int dep, int le, int s, string str, vector<string> &v) {
        if (dep == 0) {
            v.push_back(str);
            return ;
        }
        if (s > 0) {
            dfs(dep - 1, le, s-1, str + ")", v);
        }
        if (le > 0) {
            dfs(dep - 1, le - 1, s + 1, str + "(", v);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        dfs(n + n, n, 0, "", v);
        return v;
    }
};