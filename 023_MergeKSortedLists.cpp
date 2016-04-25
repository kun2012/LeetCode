/****************************************************************
Merge k sorted linked lists and return it as one sorted list.
Analyze and describe its complexity.
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
    struct cmp {
        bool operator()(ListNode* &a, ListNode *&b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode head(0);
        ListNode *p = &head;
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) pq.push(lists[i]);
        }
        while(!pq.empty()) {
            ListNode *t = pq.top();
            pq.pop();
            p->next = t;
            p = p->next;
            if (t->next) pq.push(t->next);
        }
        return head.next;
    }
};