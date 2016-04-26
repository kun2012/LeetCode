/****************************************************************
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
    
    bool dfs(TreeNode *&p, int curr, int sum) {
        if (p->left == NULL && p->right == NULL) {
            if (curr + p->val == sum) return true;
            return false;
        }
        if (p->left) {
            if (dfs(p->left, curr + p->val, sum)) return true;
        }
        if (p->right) {
            if (dfs(p->right, curr + p->val, sum)) return true;
        }
        return false;
    }

    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        return dfs(root, 0, sum);
    }
};