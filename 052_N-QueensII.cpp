/****************************************************************
Follow up for N-Queens problem.
Now, instead outputting board configurations, return the total number of distinct solutions.
****************************************************************/
class Solution {
public:
    int res = 0;
    void dfs(int i, int n, vector<bool> &col, vector<bool> &ld, vector<bool> &rd) {
        if (i == n) {
            res++;
            return;
        }     
        for (int j = 0; j < n; j++) {
            if (col[j] || ld[i + j] || rd[n - 1 + i - j]) continue;
            col[j] =  ld[i + j] = rd[n - 1 + i - j] = true;
            dfs(i + 1, n, col, ld, rd);
            col[j] =  ld[i + j] = rd[n - 1 + i - j] = false;
        }
    }
    int totalNQueens(int n) {
        vector<bool> col(n, 0), ld(n + n - 1, 0), rd(n + n - 1, 0);
        dfs(0, n, col, ld, rd);
        return res;
    }
};