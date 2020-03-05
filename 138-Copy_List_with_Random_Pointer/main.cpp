/**
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

The Linked List is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) where random pointer points to, or null if it does not point to any node.
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        Node *n = head;
        while (n != nullptr) {
            Node* t = new Node(n->val);
            t->next = n->next;
            n->next = t;
            n = n->next->next;
        }
        n = head;
        while (n != nullptr) {
            if (n->random) {
                n->next->random = n->random->next;
            }
            n = n->next->next;
        }
        n = head;
        Node *nhead = n->next;
        Node *t = nhead;
        while (n != nullptr) {
            n->next = n->next->next;
            if (t->next != nullptr) {
                t->next = t->next->next;
            }
            n = n->next;
            t = t->next;
        }
        return nhead;
    }
};
