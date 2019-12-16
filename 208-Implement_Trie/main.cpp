/**
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
 */

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        isLeaf = false;
        for (int i = 0; i < 26; i++) {
            ch[i] = nullptr;
        }
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int sz = word.size();
        Trie *node = this;
        int index = 0;
        for (int i = 0; i < sz; i++) {
            index = word[i] - 'a';
            if (node->ch[index] == nullptr) {
                Trie *nn = new Trie();
                node->ch[index] = nn;
            }
            node = node->ch[index];
        }
        node->isLeaf = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int sz = word.size();
        Trie *node = this;
        int index = 0;
        for (int i = 0; i < sz; i++) {
            index = word[i] - 'a';
            node = node->ch[index];
            if (node == nullptr) {
                return false;
            }
        }
        return node->isLeaf;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int sz = prefix.size();
        Trie *node = this;
        int index = 0;
        for (int i = 0; i < sz; i++) {
            index = prefix[i] - 'a';
            node = node->ch[index];
            if (node == nullptr) {
                return false;
            }
        }
        return true;
    }
private:
    bool isLeaf;
    Trie* ch[26];
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
