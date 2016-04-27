/****************************************************************
Given a binary tree, return the preorder traversal of its nodes' values.
For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].
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
        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> res;
            if (root == NULL) return res;
            stack<TreeNode*> st;
            st.push(root);
            while(!st.empty()) {
                TreeNode *u = st.top();
                st.pop();
                res.push_back(u->val);
                if (u->right != NULL) st.push(u->right);
                if (u->left != NULL) st.push(u->left);
            }
            return res;
        }
};
 /* Recursive
class Solution {
public:
    void dfs(TreeNode *&p, vector<int> &v) {
        if (p == NULL) return ;
        v.push_back(p->val);
        dfs(p->left, v);
        dfs(p->right, v);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        dfs(root, v);
        return v;
    }
};*/