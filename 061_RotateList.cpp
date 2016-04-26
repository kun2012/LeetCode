/****************************************************************
Given a list, rotate the list to the right by k places, where k is non-negative.
For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) return head;
        if (k == 0) return head;
        ListNode nh(0);
        nh.next = head;
        ListNode *sp = &nh, *fp = &nh;
        int len = 0;
        while(sp->next != NULL) {
            sp = sp->next;
            len++;
        }
        k = k % len;
        if (k == 0) return head;
        sp = &nh;
        for (int i = 0; i < k; i++) {
            fp = fp->next;
        }
        while(fp->next != NULL) {
            sp = sp->next;
            fp = fp->next;
        }
        if (sp == &nh) return nh.next;
        nh.next = sp->next;
        sp->next = NULL;
        fp->next = head;
        return nh.next;
    }
};