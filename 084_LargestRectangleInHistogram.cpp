/****************************************************************
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
For example,
Given heights = [2,1,5,6,2,3],
return 10.
****************************************************************/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return 0;
        stack<int> st;
        heights.push_back(0); //ensure stack is empty at last
        int ans = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (st.empty() || heights[i] > heights[st.top()]) {
                st.push(i);
            } else {
                int j = st.top();
                st.pop();
                ans = max(ans, heights[j] * (st.empty() ? i : i - st.top() - 1));
                i--;
            }
        }
        return ans;
    }
};