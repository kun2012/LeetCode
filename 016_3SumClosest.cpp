/****************************************************************
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
Return the sum of the three integers.
You may assume that each input would have exactly one solution.
For example, given array S = {-1 2 1 -4}, and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
****************************************************************/
class Solution {
public:
    int find2sum(vector<int>& nums, int start, int target) {
        int lo = start, hi = nums.size() - 1; 
        int ans = 0, dis = INT_MAX;
        while (lo < hi) {
            int tmp = nums[lo] + nums[hi];
            if (tmp < target) {
                int td = abs(tmp - target);
                if (td < dis) {
                    dis = td;
                    ans = tmp;
                }
                lo ++;
            } else if (tmp > target) {
                int td = abs(tmp - target);
                if (td < dis) {
                    dis = td;
                    ans = tmp;
                }
                hi --;
            }else {
                return tmp;
            }
        }
        return ans;
    }
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0, dis = INT_MAX;
        for (int i = 0; i + 2 < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int t = find2sum(nums, i + 1, target - nums[i]);
            if (abs(t + nums[i] - target) < dis) {
                dis = abs(t + nums[i] - target);
                res = t + nums[i];
                if (dis == 0) break;
            }
        }
        return res;
    }
};