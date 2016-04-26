/****************************************************************
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. 
You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). 
However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
****************************************************************/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        int ms = prices[0];
        int res = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] >= prices[i - 1]) {
                if (i == n - 1) {
                    res += prices[i] - ms;
                    break;
                }
                ms = min(ms, prices[i]);
                continue;
            }
            res += prices[i - 1] - ms;
            ms = prices[i];
        }
        return res;
    }
};