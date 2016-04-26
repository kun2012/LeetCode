/****************************************************************
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.
More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
****************************************************************/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int s = 0;
        int res = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            s += nums[i];
            res = max(s, res);
            if (s < 0) s = 0;
        }
        return res;
    }
};