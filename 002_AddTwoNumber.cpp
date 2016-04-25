/****************************************************************
You are given two linked lists representing two non-negative numbers.
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL, *last = NULL;
        int c = 0;
        while(l1 != NULL || l2 != NULL || c > 0) {
            if (l1 != NULL) {
                c += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                c += l2->val;
                l2 = l2->next;
            }
            ListNode *tmp = new ListNode(c % 10);
            c /= 10;
            if (head != NULL) {
                last->next = tmp;
            } else {
                head = tmp;
            }
            last = tmp;
        }
        return head;
    }
};