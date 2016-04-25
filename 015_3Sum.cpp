/****************************************************************
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.
Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
For example, given array S = {-1 0 1 2 -1 -4},
A solution set is:
(-1, 0, 1)
(-1, -1, 2)
****************************************************************/
class Solution {
public:
    void find2sum(vector<int>& nums, int start, int target, vector<vector<int> > &res) {
        int lo = start, hi = nums.size() - 1;
        while(lo < hi) {
            int tmp = nums[lo] + nums[hi];
            if (tmp < target) {
                lo++;
            } else if (tmp > target) {
                hi--;
            } else {
              res.push_back(vector<int>{ nums[start - 1], nums[lo], nums[hi] });
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

    vector<vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > res;
        for (int i = 0; i + 2 < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            find2sum(nums, i + 1, -nums[i], res);
        }
        return res;
    }
};