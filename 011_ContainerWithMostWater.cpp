/****************************************************************
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, such that the container contains the most water.
Note: You may not slant the container.
****************************************************************/
class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() <= 1) return 0;
        int s = 0, lo = 0, hi = height.size() - 1;
        while(lo < hi) {
            s = max(s, (hi - lo) * min(height[lo], height[hi]));
            if (height[lo] < height[hi]) {
                int ti = lo + 1;
                while(ti < hi && height[ti] <= height[lo])
                    ti++;
                lo = ti;
            } else {
                int ti = hi - 1;
                while(ti > lo && height[ti] <= height[hi])
                    ti--;
                hi = ti;
            }
        }
        
        return s;
    }
};