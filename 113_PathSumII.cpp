/****************************************************************
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
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
    void dfs(TreeNode *&p, int curr, int sum, vector<int> v, vector<vector<int> > &res) {
        curr += p->val;
        v.push_back(p->val);
        
        if (p->left == NULL && p->right == NULL) {
            if (curr == sum) {
                res.push_back(v);
            }
            return ;
        }
        if (p->left) {
            dfs(p->left, curr, sum, v, res);
        }
        if (p->right) {
            dfs(p->right, curr, sum, v, res);
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > res;
        if (root == NULL) return res;
        vector<int> v;
        dfs(root, 0, sum, v, res);
        return res;
    }
};