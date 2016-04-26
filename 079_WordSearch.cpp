/****************************************************************
Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. 
The same letter cell may not be used more than once.
For example,
Given board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
****************************************************************/
class Solution {
public:
    int n, m;
    vector<vector<bool> > vis;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    bool dfs(vector<vector<char> > &vv, string &word, int x, int y, int p) {
        if (p == word.size()) {
            return true;
        }
        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i], ty = y + dy[i];
            if (tx < 0 || tx >= n || ty < 0 || ty >= vv[tx].size()) continue;
            if (vis[tx][ty]) continue;
            if (vv[tx][ty] != word[p]) continue;
            vis[tx][ty] = 1;
            if (dfs(vv, word, tx, ty, p + 1)) return true;
            vis[tx][ty] = 0;
        }
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        if (word.size() == 0) return true;
        n = board.size();
        if (n == 0) return false;
        
        for (int i = 0; i < n; i++) {
            vector<bool> t;
            for (int j = 0; j < board[i].size(); j++) {
                t.push_back(0);
            }
            vis.push_back(t);
        }
        for (int i = 0; i < n; i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0]) {
                    vis[i][j] = 1;
                    if (dfs(board, word, i, j, 1)) return true;
                    vis[i][j] = 0;
                }
            }
        }
        return false;
    }
};