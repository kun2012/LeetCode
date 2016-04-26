/****************************************************************
Implement int sqrt(int x).
Compute and return the square root of x.
****************************************************************/
class Solution {
public:
//也可以用牛顿迭代法
    int bsearch(long long lo, long long hi, long long x) {
        if (lo == hi) return lo;
        if (lo + 1 == hi) {
            if (hi * hi <= x) return hi;
            return lo;
        }
        long long mid = (lo + hi) / 2;
        if (mid * mid > x) return bsearch(lo, mid - 1, x);
        return bsearch(mid, hi, x);
    }
    int mySqrt(int x) {
        if (x == 0) return 0;
        return bsearch(1, x, x);
    }
};