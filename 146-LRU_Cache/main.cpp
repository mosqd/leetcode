/**
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?
 */

#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int key;
    int val;
    Node *pre;
    Node *next;
    Node(int k, int v): key(k), val(v), pre(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, Node*> nodes;
    Node* head;
    Node* tail;
    int cap;
    int len;
public:
    LRUCache(int capacity) {
        len = 0;
        cap = capacity;
        head = nullptr;
        tail = nullptr;
    }
    ~LRUCache() {
        nodes.clear();
        Node *n = head;
        while (head != nullptr) {
            n = head;
            head = head->next;
            delete n;
        }
    }
    
    int get(int key) {
        auto it = nodes.find(key);
        if (it == nodes.end()) {
            return -1;
        }
        Node *node = it->second;
        if (node == head) {
            return node->val;
        }
        moveHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        auto it = nodes.find(key);
        if (it != nodes.end()) {
            it->second->val = value;
            Node *node = it->second;
            moveHead(node);
            return;
        }
        Node *node = nullptr;
        if (len == cap) {
            node = tail;
            nodes.erase(node->key);
            node->key = key;
            node->val = value;
            nodes[key] = node;
            moveHead(node);
        } else {
            node = new Node(key, value);
            addToHead(node);
            nodes[key] = node;
            len++;
        }
    }
private:    
    void moveHead(Node *node) {
        if (node == nullptr) {
            return;
        }
        if (node == head) {
            return;
        }
        node->pre->next = node->next;
        if (node != tail) {
            node->next->pre = node->pre;
        } else {
            tail = node->pre;
        }

        node->next = head;
        head->pre = node;
        node->pre = nullptr;
        head = node;
    }
    void addToHead(Node *node) {
        if (node == nullptr) {
            return;
        }
        if (head == nullptr) {
            head = tail = node;
            return;
        }
        node->next = head;
        head->pre = node;
        node->pre = nullptr;
        head = node;
    }
};

int main(int argc, const char *argv[])
{
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;
    cache.put(3, 3);    // evicts key 2
    cout << cache.get(2) << endl;       // returns -1 (not found)
    cache.put(4, 4);    // evicts key 1
    cout << cache.get(1) << endl;       // returns -1 (not found)
    cout << cache.get(3) << endl;       // returns 3
    cout << cache.get(4) << endl;       // returns 4

    return 0;
}
