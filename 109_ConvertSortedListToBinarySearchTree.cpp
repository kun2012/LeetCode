/****************************************************************
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
****************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    ListNode* dfs(TreeNode *&p, ListNode *lp, int lo, int hi) {
        if (lo > hi) {
            p = NULL;
            return NULL;
        }
        if (lo == hi) {
            p = new TreeNode(lp->val);
            return lp->next;
        }
        if (lo + 1 == hi) {
            p = new TreeNode(lp->val);
            return dfs(p->right, lp->next, hi, hi);
        }
        int mid = (lo + hi) / 2;
        p = new TreeNode(0);
        ListNode *ln = dfs(p->left, lp, lo, mid - 1);
        p->val = ln->val;
        return dfs(p->right, ln->next, mid + 1, hi);
    }
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode *root;
        int s = 0;
        ListNode *p = head;
        while(p != NULL) {
            p = p->next;
            s++;
        }
        dfs(root, head, 1, s);
        return root;
    }
};