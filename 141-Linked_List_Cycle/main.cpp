/**
Given a linked list, determine if it has a cycle in it.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) {
            return false;
        }
        if (head->next == nullptr) {
            return false;
        }
        if (head->next == head) {
            return true;
        }
        ListNode *n1 = head->next;
        ListNode *n2 = n1->next;
        while (n2 != nullptr) {
            if (n1 == n2) {
                return true;
            }
            if (n2->next == nullptr) {
                return false;
            }
            n1 = n1->next;
            n2 = n2->next->next;
        }
        return false;
    }
};

/**
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) {
            return false;
        }
        if (head->next == nullptr) {
            return false;
        }
        unordered_set<ListNode*> s;
        while (head != nullptr) {
            if (s.find(head) == s.end()) {
                s.insert(head);
                head = head->next;
                continue;
            }
            return true;
        }
        return false;
    }
}; 
 */
