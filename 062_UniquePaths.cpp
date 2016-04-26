/****************************************************************
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
How many possible unique paths are there?
Note: m and n will be at most 100.
****************************************************************/
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0) return 0;
        if (m == 1 || n == 1) return 1;
        n--;
        m--;
        int num = n + m;
        if (n < m) swap(n, m);
        long long x = 1;
        for (int i = n + 1; i <= num; i++) {
            x *= (long long)i;
        }
        for (int i = 1; i <= m; i++) {
            x /= i;
        }
        return x;
    }
};