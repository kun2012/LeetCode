/****************************************************************
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
    int dfs(TreeNode *&p) {
        int s1 = -1, s2 = -1;
        if (p->left) {
            s1 = dfs(p->left);
        }
        if (p->right) {
            s2 = dfs(p->right);
        }
        if (s1 == -1 && s2 == -1) return 1;
        if (s1 == -1) return 1 + s2;
        if (s2 == -1) return 1 + s1;
        return 1 + min(s1, s2);
    }
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        return dfs(root);
    }
};