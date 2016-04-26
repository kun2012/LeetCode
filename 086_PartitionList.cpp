/****************************************************************
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.
For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL || head->next == NULL) return head;
        ListNode nh1(0), nh2(0);
        ListNode *p = &nh1, *q = &nh2, *pp = head;
        while(pp != NULL) {
            if (pp->val < x) {
                p->next = pp;
                p = p->next;
                pp = pp->next;
            } else {
                q->next = pp;
                q = q->next;
                pp  = pp->next;
            }
        }
        q->next = NULL;
        p->next = nh2.next;
        return nh1.next;
    }
};