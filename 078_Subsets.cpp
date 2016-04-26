/****************************************************************
Given a set of distinct integers, nums, return all possible subsets.
Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
****************************************************************/
class Solution {
public:
    void dfs(int p, vector<int> &curr, vector<int>& nums, vector<vector<int> > &res) {
        if (p >= nums.size() ) {
            res.push_back(curr);
            return;
        }
        dfs(p + 1, curr, nums, res);
        curr.push_back(nums[p]);
        dfs(p + 1, curr, nums, res);
        curr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        vector<int> curr;
        dfs(0, curr, nums, res);
        return res;
    }
};