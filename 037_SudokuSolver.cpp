/****************************************************************
Write a program to solve a Sudoku puzzle by filling the empty cells.
Empty cells are indicated by the character '.'.
You may assume that there will be only one unique solution.
****************************************************************/
class Solution {
public:

    bool check(int x, int y, vector<vector<char> > &board) {
        for (int i = 0; i < 9; i++) {
            if (i != x && board[i][y] == board[x][y]) return false;
            if (i != y && board[x][i] == board[x][y]) return false;
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int ti = x / 3 * 3 + i, tj = y / 3 * 3 + j;
                if (ti == x && tj == y) continue;
                if (board[x][y] == board[ti][tj]) return false;
            }
        }
        return true;
    }
    bool solve(int p, vector<vector<char> > &board) {
        if (p == 81) return true;    
        int i = p / 9;
        int j = p % 9;
        if (board[i][j] != '.') return solve(p + 1, board);
        for (int k = '1'; k <= '9'; k++) {
            board[i][j] = k;
            if (check(i, j, board) && solve(p + 1, board)) return true;
            board[i][j] = '.';
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(0, board);
    }
};