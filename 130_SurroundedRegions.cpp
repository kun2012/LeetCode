/****************************************************************
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.
For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:
X X X X
X X X X
X X X X
X O X X
****************************************************************/
class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0) return ;
        queue<pair<int, int> > que;
        int n = board.size(), m = board[0].size();
        vector<vector<bool> > vis(n, vector<bool>(m, false));
        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O') {
                que.push(pair<int, int>(0, i));
                vis[0][i] = true;
            }
            if (n - 1 != 0) {
                if (board[n-1][i] == 'O') {
                    que.push(pair<int, int>(n-1, i));
                    vis[n - 1][i] = true;
                }
            }
        }
        for (int i = 1; i < n - 1; i++) {
            if (board[i][0] == 'O') {
                que.push(pair<int, int>(i, 0));
                vis[i][0] = true;
            }
            if (m - 1 != 0) {
                if (board[i][m - 1] == 'O') {
                    que.push(pair<int, int>(i, m - 1));
                    vis[i][m - 1] = true;
                }
            }
        }
        while(!que.empty()) {
            pair<int, int> u = que.front();
            que.pop();
            int x = u.first, y = u.second;
            board[x][y] = '#';
            for (int i = 0; i < 4; i++) {
                int tx = x + dx[i], ty = y + dy[i];
                if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
                if (vis[tx][ty]) continue;
                if (board[tx][ty] == 'O') {
                    que.push(pair<int, int>(tx, ty));
                    vis[tx][ty] = true;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};