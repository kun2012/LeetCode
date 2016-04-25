/****************************************************************
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.
Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
A solution set is:
(-1,  0, 0, 1)
(-2, -1, 1, 2)
(-2,  0, 0, 2)
****************************************************************/
class Solution {
public:
    void find2sum(vector<int>& nums, int start, int target, int x, int y, vector<vector<int> > &res) {
        int lo = start, hi = nums.size() - 1;
        while(lo < hi) {
            int tmp = nums[lo] + nums[hi];
            if (tmp < target) {
                lo++;
            } else if (tmp > target) {
                hi--;
            } else {
              res.push_back(vector<int>{ x, y, nums[lo], nums[hi] });
              int k = lo + 1;
              while(k < hi && nums[k] == nums[lo]) {
                  k++;
              }
              lo = k;
              k = hi - 1;
              while(k > lo && nums[k] == nums[hi]) {
                  k--;
              }
              hi = k;
            }
        }
    }
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > res;
        for (int i = 0; i + 3 < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j + 2 < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                find2sum(nums, j + 1, target - nums[i] - nums[j], nums[i], nums[j], res);
            }
        }
        return res;
    }
};