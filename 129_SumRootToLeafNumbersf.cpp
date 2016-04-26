/****************************************************************
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
An example is the root-to-leaf path 1->2->3 which represents the number 123.
Find the total sum of all root-to-leaf numbers.
For example,
    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Return the sum = 12 + 13 = 25.
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
    int dfs(TreeNode *&p, int s) {
        int tmp = s * 10 + p->val;
        if (!p->left && !p->right) return tmp;
        int t1 = 0, t2 = 0;
        if (p->left) t1 = dfs(p->left, tmp);
        if (p->right) t2 = dfs(p->right, tmp);
        return t1 + t2;
    }
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        return dfs(root, 0);
    }
};