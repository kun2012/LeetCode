/****************************************************************
Given a binary tree, determine if it is a valid binary search tree (BST).
Assume a BST is defined as follows:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
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
    bool dfs(TreeNode *&p, int &ls, int &hs) {
        if (p->left == NULL && p->right == NULL) {
            ls = hs = p->val;
            return true;
        }
        ls = hs = p->val;
        if(p->left != NULL) {
            int t1 = 0, t2 = 0;
            if (!dfs(p->left, t1, t2)) return false;
            if (t2 >= p->val) return false;
            ls = t1;
        }
        if (p->right != NULL) {
            int t1 = 0, t2 = 0;
            if (!dfs(p->right, t1, t2)) return false;
            if (t1 <= p->val) return false;
            hs = t2;
        }
        return true;
    }
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        int ls = 0, hs = 0;
        return dfs(root, ls, hs);
    }
};