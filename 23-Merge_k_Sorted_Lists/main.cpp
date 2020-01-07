/**
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
 */

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
    static bool cmp(ListNode* n1, ListNode* n2) {
        return n1->val > n2->val;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        auto cmp = [](ListNode* n1, ListNode* n2) { return n1->val > n2->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q(cmp);
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                q.push(lists[i]);
            }
        }
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        while (!q.empty()) {
            ListNode *n = q.top();
            q.pop();
            p->next = n;
            p = n;
            if (n->next != nullptr) {
                q.push(n->next);
            }
        }
        return head->next;
    }
};
