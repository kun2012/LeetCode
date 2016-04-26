/****************************************************************
Given a sorted linked list, delete all duplicates such that each element appear only once.
For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
****************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return head;
        ListNode *p = head, *q = head->next;
        while(q != NULL) {
            if (q->val == p->val) {
                q = q->next;
                continue;
            }
            p->next = q;
            q = q->next;
            p = p->next;
        }
        p->next = NULL;
        return head;
    }
};