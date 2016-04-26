/****************************************************************
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode *> s1, s2;
        vector<vector<int> > res;
        if (!root) return res;
        s1.push(root);
        vector<int> t;
        
        int flag = 1;
        
        while(!s1.empty()) {
            TreeNode *p = s1.top();
            s1.pop();
            t.push_back(p->val);
            if (flag) {
                if (p->left) s2.push(p->left);
                if (p->right) s2.push(p->right);
            } else {
                if (p->right) s2.push(p->right);
                if (p->left) s2.push(p->left);
            }
            if (s1.empty()) {
                res.push_back(t);
                t.clear();
                swap(s1, s2);
                flag = 1 - flag;
            }
        }
        return res;
    }
};