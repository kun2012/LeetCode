/****************************************************************
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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
    void dfs(vector<TreeNode*> &vt, int lo, int hi) {
        if (lo == hi) {
            TreeNode *p = new TreeNode(lo);
            vt.push_back(p);
            return ;
        }
        if (lo > hi) {
            vt.push_back(NULL);
            return ;
        }
        vector<TreeNode *> lp;
        vector<TreeNode *> rp;
        for (int i = lo; i <= hi; i++) {
            lp.clear();
            rp.clear();
            dfs(lp, lo, i - 1);
            dfs(rp, i + 1, hi);
            for (int j = 0; j < lp.size(); j++) {
                for (int k = 0; k < rp.size(); k++) {
                    TreeNode *p = new TreeNode(i);
                    p->left = lp[j];
                    p->right = rp[k];
                    vt.push_back(p);
                }
            }
        }
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> root;
        if (n == 0) return root;
        dfs(root, 1, n);
        return root;
    }
};