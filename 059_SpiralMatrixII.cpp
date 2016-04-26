/****************************************************************
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
For example,
Given n = 3,
You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
****************************************************************/
class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    void dfs(int p, int n, int x, int y, int k, vector<vector<int> > &v) {
        if (p > n * n) return ;
        v[x][y] = p;
        int tx = x + dx[k], ty = y + dy[k];
        if (tx < 0 || tx >= n || ty < 0 || ty >= n || v[tx][ty] != 0) {
            k++;
            if (k == 4) k = 0;
            tx = x + dx[k], ty = y + dy[k];
        }
        dfs(p + 1, n, tx, ty, k, v);
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > v(n, vector<int>(n, 0));
        if (n == 0) return v;
        dfs(1, n, 0, 0, 0, v);
        return v;
    }
};