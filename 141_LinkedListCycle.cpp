/****************************************************************
Given a linked list, determine if it has a cycle in it.
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
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        ListNode *sp = head, *fp = head;
        while(fp->next != NULL && fp->next->next != NULL) {
            sp = sp->next;
            fp = fp->next->next;
            if (sp == fp) return true;
        }
        return false;
    }
};