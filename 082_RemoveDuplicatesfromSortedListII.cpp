/****************************************************************
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
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
        if (head == NULL || head->next == NULL) return head;
        ListNode nh(0);
        ListNode *p = &nh, *q1 = head, *q2 = head->next;
        while(true) {
            if (q1->val != q2->val) {
                p->next = q1;
                p = p->next;
                q1 = q2;
                q2 = q2->next;
                if (q2 == NULL) {
                    p->next = q1;
                    p = q1;
                    break;
                }
                continue;
            }
            while(q2 != NULL && q1->val == q2->val) {
                q2 = q2->next;
            }
            if (q2 == NULL) {
                break;
            } else {
                q1 = q2;
                q2 = q2->next;
                if (q2 == NULL) {
                    p->next = q1;
                    p = q1;
                    break;
                }
            }
        }
        p->next = NULL;
        return nh.next;
    }
};