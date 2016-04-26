/****************************************************************
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete at most two transactions.
Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
****************************************************************/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        vector<int> f(n + 1, 0);
        int maxn = prices[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            maxn = max(maxn, prices[i]);
            f[i] = max(f[i + 1], maxn - prices[i]);
        }
        int ms = prices[0];
        int res = 0;
        for (int i = 1; i < n; i++) {
            ms = min(ms, prices[i]);
            res = max(res, prices[i] - ms + f[i + 1]);
        }
        return res;
    }
};