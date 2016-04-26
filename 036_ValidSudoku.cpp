/****************************************************************
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
Note:
A valid Sudoku board (partially filled) is not necessarily solvable.
Only the filled cells need to be validated.
****************************************************************/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        //row & column
        for (int i = 0; i < n; i++) {
            vector<bool> vis(n, false);
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                if (vis[board[i][j]]) return false;
                vis[board[i][j]] = true;
            }
            vector<bool> vis2(n, false);
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.') continue;
                if (vis2[board[j][i]]) return false;
                vis2[board[j][i]] = true;
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                vector<bool> vis(n, false);
                for (int h = 0; h < 3; h++) {
                    int x = i * 3 + h;
                    for (int k = 0; k < 3; k++) {
                        int y = j * 3 + k;
                        if (board[x][y] == '.') continue;
                        if (vis[board[x][y]]) return false;
                        vis[board[x][y]] = true;
                    }
                }
            }
        }
        return true;
    }
};