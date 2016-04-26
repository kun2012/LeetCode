/****************************************************************
Given a triangle, find the minimum path sum from top to bottom. 
Each step you may move to adjacent numbers on the row below.
For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
****************************************************************/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n == 0) return 0;
        vector<int> p(n, 0), q(n, 0);
        p[0] = triangle[0][0];
        for (int i = 1; i < n; i++) {
            q[0] = p[0] + triangle[i][0];
            q[i] = p[i - 1] + triangle[i][i];
            for (int j = 1; j < i; j++)
                q[j] = min(p[j - 1], p[j]) + triangle[i][j];
            swap(p, q);
        }
        int res = p[0];
        for (int i = 1; i < n; i++) {
            res = min(p[i], res);
        }
        return res;
    }
};