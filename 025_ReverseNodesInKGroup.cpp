/****************************************************************
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
You may not alter the values in the nodes, only nodes itself may be changed.
Only constant memory is allowed.
For example,
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5
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

    ListNode* reverse(ListNode* &p1, ListNode* &p2, int k) {
        ListNode *pre = p1, *curr = p1->next, *next = p1->next;
        p1->next = NULL;
        for (int i = 0; i < k - 1; i++) {
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        return p2;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k <= 1) return head;
        ListNode tn(0);
        tn.next = head;
        ListNode *t(&tn), *h(head), *p1 = head, *p2 = head;
        while(h) {
            for (int i = 0; i < k - 1 && p2; i++)
                p2 = p2->next;
            if (p2) {
                h = p2->next;
                t->next = reverse(p1, p2, k);
                t = p1;
                p1 = p2 = h;
            } else {
                t->next = p1;
                h = p2;
            }
        }
        return tn.next;
    }
};