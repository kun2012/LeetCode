/****************************************************************
Follow up for problem "Populating Next Right Pointers in Each Node".
What if the given tree could be any binary tree? Would your previous solution still work?
Note:
You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
****************************************************************/
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) return ;
        root->next = NULL;
        TreeLinkNode *p = root, *tmp, *th = new TreeLinkNode(0);
        while(p != NULL) {
            th->next = NULL;
            TreeLinkNode *last = th;
            while(p != NULL) { //handle one level
                if (p->left != NULL) {
                    last->next = p->left;
                    last = p->left;
                }
                if (p->right != NULL) {
                    last->next = p->right;
                    last = p->right;
                }
                p = p->next;
            }
            p = th->next;
        }
    }
};