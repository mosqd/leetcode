/**
Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)  {
            return head;
        }
        ListNode *one = head;
        ListNode *two = head->next;
        ListNode *three;
        head->next = nullptr;
        while (two != nullptr) {
            three = two->next;
            two->next = one;
            one = two;
            two = three;
        }
        return one;
    }
};
