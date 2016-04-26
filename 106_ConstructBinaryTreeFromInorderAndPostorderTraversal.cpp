/****************************************************************
Given inorder and postorder traversal of a tree, construct the binary tree.
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
    void dfs(TreeNode *&p, vector<int> &in, int x, int y, vector<int> &po, int u, int v) {
        if (u > v) {
            p = NULL;
            return ;
        }
        p = new TreeNode(po[v]);
        int j = x;
        while(j <= y && in[j] != po[v]) j++;
        int lc = j - x;
        dfs(p->left, in, x, j - 1, po, u, u + lc - 1);
        dfs(p->right, in, j + 1, y, po, u + lc, v - 1);
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode *root;
        dfs(root, inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
        return root;
    }
};