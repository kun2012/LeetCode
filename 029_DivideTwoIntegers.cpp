/****************************************************************
Divide two integers without using multiplication, division and mod operator.
If it is overflow, return MAX_INT.
****************************************************************/
class Solution {
public:
    vector<long long> v;
    int divide(int dividend, int divisor) {
        if (dividend == -2147483648 && divisor == -1) 
            return 2147483647;
        long long a = dividend, b = divisor;
        if (b == 0) return INT_MAX;
        if (a == 0) return 0;
        int flag = false;
        if (a > 0 && b < 0 || a < 0 && b > 0) {
            a = abs(a);
            b = abs(b);
            flag = true;
        }
        if (a < 0 && b < 0) {
            a = abs(a);
            b = abs(b);
        }
        if (b > a) return 0;
        if (b == 1) {
            if (flag) return -a;
            else return a;
        }
        v.push_back(0);
        v.push_back(b);
        int i = 1;
        while(true) {
            long long t = v[i];
            if (t + t > a) break;
            v.push_back(t + t);
            i++;
        }
        long long ans = 0;
        for (int j = i; j >= 1; j--) {
            if (v[j] <= a) {
                ans += (1<<(j-1));
                a -= v[j];
            }
        }
        if(flag) ans = -ans;
        return ans;
    }
};