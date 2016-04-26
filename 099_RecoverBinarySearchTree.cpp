/****************************************************************
Two elements of a binary search tree (BST) are swapped by mistake.
Recover the tree without changing its structure.
Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
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
    TreeNode *first, *second, *prev;
    void dfs(TreeNode *&p) {
        if (p->left != NULL) dfs(p->left);
        if (prev != NULL && prev->val > p->val) {
            if (first == NULL) {
                first = prev;
            }
            if (first != NULL) {
                second = p;
            }
        }
        prev = p;
        if (p->right != NULL) dfs(p->right);
    }
    void recoverTree(TreeNode* root) {
        first = second = NULL;
        dfs(root);
        if (first != NULL && second != NULL) {
            swap(first->val, second->val);
        }
    }
};