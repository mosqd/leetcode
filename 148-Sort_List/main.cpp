/**
Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        qsort(head, nullptr);
        return head;
    }
    void qsort(ListNode *head, ListNode *tail) {
        if (head != nullptr && head != tail && head->next != tail) {
            ListNode *p = partition(head, tail);
            qsort(head, p);
            qsort(p->next, tail);
        }
    }
    ListNode* partition(ListNode *head, ListNode *tail) {
        if (head == nullptr) {
            return nullptr;
        }
        int v = head->val;
        ListNode *k = head;
        ListNode *p = head;
        for (head = head->next; head != tail; head = head->next) {
            if (head->val < v) {
                std::swap(head->val, p->val);
                if (p == k) {
                    k = head;
                }
                p = p->next;
            }
        }
        std::swap(p->val, k->val);
        return p;
    }
};
