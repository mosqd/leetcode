/**
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        bool addOne = false;
        int num = 0;
        while (l1 != nullptr || l2 != nullptr) {
            num = 0;
            if (l1 != nullptr) {
                num = l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                num += l2->val;
                l2 = l2->next;
            }
            num += addOne ? 1 : 0;
            p->next = new ListNode(num % 10);
            addOne = false;
            if (num / 10) {
                addOne = true;
            }
            p = p->next;
        }
        if (addOne) {
            p->next = new ListNode(1);
        }
        return head->next;
        
    }
};
