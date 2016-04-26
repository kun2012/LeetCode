/****************************************************************
Given a collection of distinct numbers, return all possible permutations.
For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
****************************************************************/
class Solution {
public:
    vector<vector<int> > res;
    void dfs(vector<bool> &vis, vector<int> &nums, vector<int> cur) {
        if (cur.size() == nums.size()) {
            res.push_back(cur);
            return ;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (vis[i]) continue;
            cur.push_back(nums[i]);
            vis[i] = true;
            dfs(vis, nums, cur);
            vis[i] = false;
            cur.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> vis(n, false);
        vector<int> cur;
        dfs(vis, nums, cur);
        return res;
    }
};