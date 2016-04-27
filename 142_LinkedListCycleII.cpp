/****************************************************************
Given a linked list, return the node where the cycle begins. 
If there is no cycle, return null.
Note: Do not modify the linked list.
Follow up:
Can you solve it without using extra space?
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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) return head;
        if (head->next == NULL) return NULL;
        ListNode *sp = head, *fp = head;
        while(fp != NULL && fp->next != NULL) {
            sp = sp->next;
            fp = fp->next->next;
            if (sp == fp) break;
        }
        if (sp != fp) return NULL;
        sp = head;
        while(true) {
            if (fp == sp) break;
            sp = sp->next;
            fp = fp->next;
        }
        return sp;
    }
};