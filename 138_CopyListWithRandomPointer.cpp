/****************************************************************
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.=
Return a deep copy of the list.
****************************************************************/
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return NULL;
        RandomListNode *p = head;
        while(p != NULL) {
            RandomListNode *q = new RandomListNode(p->label);
            q->next = p->next;
            p->next = q;
            p = q->next;
        }
        p = head;
        while(p != NULL) {
            if (p->random == NULL) {
                p->next->random = NULL;
            }else {
                p->next->random = p->random->next;
            }
            p = p->next->next;
        }
        RandomListNode *nh = head->next;
        RandomListNode *q = nh;
        head->next = head->next->next;
        p = head->next;
        while(p != NULL) {
            q->next = p->next;
            q = q->next;
            p->next = p->next->next;
            p = p->next;
        }
        return nh;
    }
/* hash table
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return NULL;
        map<RandomListNode*, RandomListNode*> lm;
        RandomListNode *nh = new RandomListNode(head->label);
        lm[head] = nh;
        RandomListNode *p = nh, *q = head->next;
        while(q != NULL) {
            p->next = new RandomListNode(q->label);
            p = p->next;
            lm[q] = p;
            q = q->next;
        }
        q = head;
        p = nh;
        while(q != NULL) {
            p->random = lm[q->random];
            q = q->next;
            p = p->next;
        }
        return nh;
    }
    */
};