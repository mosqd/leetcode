/**
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        if (head->next->next == nullptr && head->val == head->next->val) {
            return true;
        }
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast != nullptr) {
            slow = slow->next;
        }
        fast = reverse(slow);
        slow = head;
        while (fast != nullptr) {
            if (slow->val == fast->val) {
                slow = slow->next;
                fast = fast->next;
                continue;
            }
            return false;
        }
        return true;
    }
    ListNode* reverse(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *one = head;
        ListNode *two = one->next;
        ListNode *three = nullptr;
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
