/****************************************************************
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
For example,
There exist two distinct solutions to the 4-queens puzzle:
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
****************************************************************/
class Solution {
public:
    vector<vector<string> > res;
    void dfs(int i, int n, vector<string> &a, vector<bool> &col, vector<bool> &ld, vector<bool> &rd) {
        if (i == n) {
            res.push_back(a);
            return;
        }
        for (int j = 0; j < n; j++) {
            if (col[j] || ld[i + j] || rd[n - 1 + i - j]) continue;
            a[i][j] = 'Q';
            col[j] =  ld[i + j] = rd[n - 1 + i - j] = true;
            dfs(i + 1, n, a, col, ld, rd);
            a[i][j] = '.';
            col[j] =  ld[i + j] = rd[n - 1 + i - j] = false;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> col(n, 0), ld(n + n - 1, 0), rd(n + n - 1, 0);
        vector<string> a(n);
        for (int i = 0; i < n; i++) {
            string s = "";
            for (int i = 0; i < n; i++) {
                s = s + ".";
            }
            a[i] = s;
        }
        dfs(0, n, a, col, ld, rd);
        return res;
    }
};