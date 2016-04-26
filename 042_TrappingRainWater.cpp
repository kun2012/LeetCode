/****************************************************************
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
****************************************************************/
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        vector<int> lh(n, 0), rh(n, 0);
        lh[0] = height[0];
        for (int i = 1; i < n; i++) {
            lh[i] = max(lh[i - 1], height[i]);
        }
        rh[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rh[i] = max(rh[i + 1], height[i]);
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += min(lh[i], rh[i]) - height[i];
        }
        return ans;
    }
};