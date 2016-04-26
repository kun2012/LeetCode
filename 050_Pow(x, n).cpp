/****************************************************************
Implement pow(x, n).
****************************************************************/
class Solution {
public:
    //要处理负指数
    //指数非常大
    double kpow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        int m = n / 2;
        double t = kpow(x, m);
        return t * t * (n & 1 ? x : 1);
    }
    
    double myPow(double x, int n) {
        bool flag = (n < 0 ? 1 : 0);
        double t = kpow(x, abs(n));
        return (flag ? 1 / t : t);
    }
};