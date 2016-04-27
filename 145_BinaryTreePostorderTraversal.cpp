/****************************************************************
Given a binary tree, return the postorder traversal of its nodes' values.
For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            TreeNode *u = st.top();
            st.pop();
            res.push_back(u->val);
            if (u->left != NULL) {
                st.push(u->left);
            }
            if (u->right != NULL) {
                st.push(u->right);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
 /*
class Solution {
public:
    void dfs(TreeNode *&p, vector<int> &v) {
        if (p == NULL) return ;
        dfs(p->left, v);
        dfs(p->right, v);
        v.push_back(p->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        dfs(root, v);
        return v;
    }
};*/