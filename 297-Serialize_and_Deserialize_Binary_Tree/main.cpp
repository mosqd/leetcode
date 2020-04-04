/**
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Example: 

You may serialize the following tree:

    1
   / \
  2   3
     / \
    4   5

as "[1,2,3,null,null,4,5]"
Clarification: The above format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string itoa(int i) {
        stringstream ss;
        ss << i;
        string s;
        ss >> s;
        return s;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return string();
        }

        string str;
        serialize(root, str);
        return str;
    }
    void serialize(TreeNode *node, string &str) {
        if (node == nullptr) {
            str += '#';
            return;
        }
        str += itoa(node->val) + "!";
        serialize(node->left, str);
        serialize(node->right, str);
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }
        int index = 0;
        return deserialize(data, index);
    }
    TreeNode* deserialize(string& str, int &index) {
        if (str[index] == '#') {
            index++;
            return nullptr;
        }
        int n = 0;
        int sign = 1;
        if (str[index] == '-') {
            sign = -1;
            index++;
        }
        while (str[index] != '!') {
            n = n*10 + (str[index] - '0');
            index++;
        }
        n *= sign;
        index++;
        TreeNode *p = new TreeNode(n);
        p->left = deserialize(str, index);
        p->right = deserialize(str, index);
        return p;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
