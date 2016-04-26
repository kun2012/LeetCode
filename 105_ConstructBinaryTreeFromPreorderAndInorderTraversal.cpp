/****************************************************************
Given preorder and inorder traversal of a tree, construct the binary tree.
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return NULL;
        TreeNode *p = new TreeNode(preorder[0]);
        if (preorder.size() == 1) {
            return p;
        }
        
    }
};