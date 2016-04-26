/****************************************************************
Given a binary tree, return the inorder traversal of its nodes' values.
For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].
Note: Recursive solution is trivial, could you do it iteratively?
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

    void dfs(TreeNode *&p, vector<int> &v) {
        if (p == NULL) return ;
        dfs(p->left, v);
         v.push_back(p->val);
        dfs(p->right, v);
       
    }
    vector<int> inorderTraversal(TreeNode* root) {
                vector<int> v;
        dfs(root, v);
        return v;
    }
};