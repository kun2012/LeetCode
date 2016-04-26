/****************************************************************
Given a binary tree, flatten it to a linked list in-place.
For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
Hints:
If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.
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
    TreeNode *flat(TreeNode *&p) {
        if (p == NULL) return NULL;
        TreeNode *p1 = flat(p->left);
        TreeNode *p2 = flat(p->right);
        TreeNode *tri = p->right;
        TreeNode *cur = NULL;
        if (p1 != NULL) {
            p->right = p->left;
            p->left = NULL;
            cur = p1;
        } else {
            cur = p;
        }
        if (p2 != NULL) {
            cur->right = tri;
            return p2;
        } else {
            return cur;
        }
    }
    void flatten(TreeNode* root) {
        flat(root);
    }
};