/****************************************************************
Merge two sorted linked lists and return it as a new list.
The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode head(0);
        ListNode *p = &head;
        while(l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            }else {
                p->next = l2;
                l2 = l2->next;
            }
             p = p->next;
        }
        if (l1) p->next = l1;
        else if (l2) p->next = l2;
        return head.next;
    }
};