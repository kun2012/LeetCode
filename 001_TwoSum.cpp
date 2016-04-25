/****************************************************************
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution.
Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
****************************************************************/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;
        for (int i = 0; i < nums.size(); i++) {
            um[nums[i]] = i;
        }
        vector<int> ans(2);
        for (int i = 0; i < nums.size(); i++) {
            if (um.find(target - nums[i]) == um.end()) continue;
            int x = um[target - nums[i]];
            if (x == i) continue;
            ans[0] = i;
            ans[1] = x;
            break;
        }
        return ans;
    }
};