/****************************************************************
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
You must do this in-place without altering the nodes' values.
For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
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
    void reverse(ListNode *&head) {
        ListNode nh(0);
        ListNode *p = &nh, *t;
        while(head != NULL) {
            t = head->next;
            head->next = p->next;
            p->next = head;
            head = t;
        }
        head = nh.next;
    }
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) return ;
        ListNode *sp = head, *fp = head->next;
        while(fp->next != NULL && fp->next->next != NULL) {
            sp = sp->next;
            fp = fp->next->next;
        }
        fp = sp->next;
        sp->next = NULL;
        reverse(fp);
        ListNode nh(0);
        ListNode *p = &nh;
        sp = head;
        
        while(sp != NULL && fp != NULL) {
            p->next = sp;
            sp = sp->next;
            p = p->next;
            p->next = fp;
            fp = fp->next;
            p = p->next;
        }
        if (fp != NULL) {
            p->next = fp;
        }
        head = nh.next;
    }
};