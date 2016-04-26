/****************************************************************
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
****************************************************************/
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        vector<int> h(m + 1, 0);
        stack<int> st;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m + 1; j++) {
                if (j < m) {
                    if (matrix[i][j] == '0') h[j] = 0;
                    else h[j]++;
                }
                while(true) {
                    if (st.empty() || h[j] > h[st.top()]) {
                        st.push(j);
                        break;
                    }
                    int k = st.top();
                    st.pop();
                    ans = max(ans, h[k] * (st.empty() ? j : j - st.top() - 1));
                }
            }
            st.pop(); //pop the last 0
        }
        return ans;
    }
};