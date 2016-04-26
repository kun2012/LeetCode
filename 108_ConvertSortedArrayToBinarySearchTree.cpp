/****************************************************************
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
****************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode *&p, vector<int> &nums, int lo, int hi) {
        if (lo > hi) {
            p = NULL;
            return ;
        }    
        if (lo == hi) {
            p = new TreeNode(nums[lo]);
            return ;
        }
        if (lo + 1 == hi) {
            p = new TreeNode(nums[hi]);
            dfs(p->left, nums, lo, lo);
            return ;
        }
        int mid = (lo + hi) / 2;
        p = new TreeNode(nums[mid]);
        dfs(p->left, nums, lo, mid - 1);
        dfs(p->right, nums, mid + 1, hi);
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *root = NULL;
        dfs(root, nums, 0, nums.size() - 1);
        return root;
    }
};