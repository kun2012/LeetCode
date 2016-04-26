/****************************************************************
Given a binary tree, find the maximum path sum.
For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. 
The path does not need to go through the root.
For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
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
    void dfs(TreeNode *&p, pair<int, int> &a) {
        if (p->left == NULL && p->right == NULL) {
            a.first = a.second = p->val;
            return ;
        }
        pair<int, int> le(INT_MIN, INT_MIN), ri(INT_MIN, INT_MIN);
        if (p->left) dfs(p->left, le);
        if (p->right) dfs(p->right, ri);
        a.second = max(p->val, p->val + max(le.second, ri.second));
        int c = p->val;
        if (p->left) c += le.second;
        if (p->right) c += ri.second;
        a.first = max( max(le.first, ri.first), max(c, a.second));
    }
    int maxPathSum(TreeNode* root) {
        if (root == NULL) return 0;
        pair<int, int> res;
        dfs(root, res);
        return res.first;
    }
};