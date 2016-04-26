/****************************************************************
Follow up for "Unique Paths":
Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space is marked as 1 and 0 respectively in the grid.
For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.
Note: m and n will be at most 100.
****************************************************************/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        if (n == 0) return 0;
        int m = obstacleGrid[0].size();
        vector<vector<int> > f(n, vector<int>(m, 0));
        if (obstacleGrid[0][0] == 1) return 0;
        f[0][0] = 1;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) continue;
                if (obstacleGrid[i][j] == 1) continue;
                if (i == 0) {
                    f[i][j] = f[i][j - 1];
                } else if (j == 0) {
                    f[i][j] = f[i - 1][j];
                } else {
                    f[i][j] = f[i][j - 1] + f[i - 1][j];
                }
            }
        }
        return f[n - 1][m - 1];
    }
};