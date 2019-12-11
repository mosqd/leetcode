 /**
 Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

Note: Do not modify the linked list.
  */

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        if (head->next == nullptr) {
            return nullptr;
        }
        unordered_set<ListNode*> s;
        while (head != nullptr) {
            if (s.find(head) == s.end()) {
                s.insert(head);
                head = head->next;
                continue;
            }
            return head;
        }
        return nullptr;
    }
};

/**
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        if (head->next == nullptr) {
            return nullptr;
        }
        if (head->next == head) {
            return head;
        }
        ListNode *n1 = head->next;
        ListNode *n2 = n1->next;
        while (n2 != nullptr) {
            if (n1 == n2) {
                break;
            }
            if (n2->next == nullptr) {
                return nullptr;
            }
            n1 = n1->next;
            n2 = n2->next->next;
        }
        if (n2 == nullptr) {
            return nullptr;
        }
        n1 = head;
        while (n1 != n2) {
            n1 = n1->next;
            n2 = n2->next;
        }
        return n1;
    }
};
 */
