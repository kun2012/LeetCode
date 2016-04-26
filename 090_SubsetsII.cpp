/****************************************************************
Given a collection of integers that might contain duplicates, nums, return all possible subsets.
Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,2], a solution is:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
****************************************************************/
class Solution {
public:
    vector<vector<int>> res;
    void dfs(int p, vector<int> &nums, vector<int> &cur) {
        res.push_back(cur);
        int last = 0;
        for (int i = p; i < nums.size(); i++) {
            if (i != p && nums[i] == nums[i - 1]) continue;
            last = nums[i];
            cur.push_back(nums[i]);
            dfs(i + 1, nums, cur);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> cur;
        dfs(0, nums, cur);
        return res;
    }
};