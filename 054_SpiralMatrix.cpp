/****************************************************************
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
For example,
Given the following matrix:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
****************************************************************/
class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    void dfs(int p, int x, int y, int m, int n, int k, vector<vector<int> > &mat, vector<vector<bool> > &vis, vector<int> &res) {
        if (p > m * n) return ;
        res.push_back(mat[x][y]);
        vis[x][y] = true;
        int tx = x + dx[k], ty = y + dy[k];
        if (tx < 0 || tx >= m || ty < 0 || ty >= n || vis[tx][ty]) {
            k++;
            if (k == 4) k = 0;
            tx = x + dx[k], ty = y + dy[k];
        }
        dfs(p + 1, tx, ty, m, n, k, mat, vis, res);
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        if (m == 0) return res;
        int n = matrix[0].size();
        vector<vector<bool> > vis(m, vector<bool>(n, false));
        dfs(1, 0, 0, m, n, 0, matrix, vis, res);
    }
};