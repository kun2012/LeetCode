/****************************************************************
Write an efficient algorithm that searches for a value in an m x n matrix.
This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example, Consider the following matrix:
[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
****************************************************************/
class Solution {
public:
    bool bsearch(int lo, int hi, vector<vector<int> > &a, int x) {
        int m = a[0].size();
        if (lo == hi) {
            if (a[lo / m][lo % m] == x) return true;
            return false;
        }
        if (lo + 1 == hi) {
            if (a[lo / m][lo % m] == x) return true;
            if (a[hi / m][hi % m] == x) return true;
            return false;
        }
        
        int mid = (lo + hi) / 2;
        if (a[mid / m][mid % m] < x) return bsearch(mid + 1, hi, a, x);
        return bsearch(lo, mid, a, x);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n == 0) return false;
        int m = matrix[0].size();
        int s = n * m;
        return bsearch(0, s - 1, matrix, target);
    }
};