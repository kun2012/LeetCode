/****************************************************************
Given a collection of numbers that might contain duplicates, return all possible unique permutations.
For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
****************************************************************/
class Solution {
public:
    vector<vector<int> > res;
    void dfs(vector<bool> &vis, vector<int> &nums, vector<int> cur) {
        if (cur.size() == nums.size()) {
            res.push_back(cur);
            return ;
        }
        bool first = true; 
        int last = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (vis[i]) continue;
            if (!first && nums[i] == last) continue;
            last = nums[i];
            first = false;
            cur.push_back(nums[i]);
            vis[i] = true;
            dfs(vis, nums, cur);
            vis[i] = false;
            cur.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<bool> vis(n, false);
        vector<int> cur;
        dfs(vis, nums, cur);
        return res;
    }
};