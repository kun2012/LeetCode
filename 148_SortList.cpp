/****************************************************************
Sort a linked list in O(n log n) time using constant space complexity.
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
    void merge_sort_list(ListNode *&head) {
        ListNode *sp = head, *fp = head->next;
        if (fp == NULL) return ;
        while(sp->next != NULL && fp->next != NULL && fp->next->next != NULL) {
            sp = sp->next;
            fp = fp->next->next;
        }
        fp = sp->next;
        sp->next = NULL;
        merge_sort_list(head);
        merge_sort_list(fp);
        ListNode newhead(0);
        sp = &newhead;
        while(head != NULL && fp != NULL) {
            if (head != NULL && fp != NULL) {
                if (head->val < fp->val) {
                    sp->next = head;
                    head = head->next;
                } else {
                    sp->next = fp;
                    fp = fp->next;
                }
                sp = sp->next;
                continue;
            }
        }
        if (head == NULL) {
            sp->next = fp;
        } else {
            sp->next = head;
        }
        head = newhead.next;
    }
    ListNode* sortList(ListNode* head) {
        if (head == NULL) return head;
        merge_sort_list(head);
        return head;
    }
};