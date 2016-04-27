/****************************************************************
Sort a linked list using insertion sort.
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
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL) return head;
        ListNode *st = head->next;
        ListNode *st_pre = head;
        while(st != NULL) {
            ListNode *p = head;
            ListNode *pre = NULL;
            while(p->val < st->val) {
                pre = p;
                p = p->next;
            }
            if (p != st) {
                st_pre->next = st->next;
                st->next = p;
                if(p == head) {
                    head = st;
                } else {
                    pre->next = st;
                }
                st = st_pre->next;
            }else {
                st_pre = st;
                st = st->next;
            }
        }
        return head;
    }
};