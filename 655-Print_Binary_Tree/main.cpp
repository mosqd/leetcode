/**
Given the root of a binary tree, construct a 0-indexed m x n string matrix res that represents a formatted layout of the tree. The formatted layout matrix should be constructed using the following rules:

The height of the tree is height and the number of rows m should be equal to height + 1.
The number of columns n should be equal to 2height+1 - 1.
Place the root node in the middle of the top row (more formally, at location res[0][(n-1)/2]).
For each node that has been placed in the matrix at position res[r][c], place its left child at res[r+1][c-2height-r-1] and its right child at res[r+1][c+2height-r-1].
Continue this process until all the nodes in the tree have been placed.
Any empty cells should contain the empty string "".
Return the constructed matrix res.

 

Example 1:


Input: root = [1,2]
Output: 
[["","1",""],
 ["2","",""]]
Example 2:


Input: root = [1,2,3,null,4]
Output: 
[["","","","1","","",""],
 ["","2","","","","3",""],
 ["","","4","","","",""]]
 

Constraints:

The number of nodes in the tree is in the range [1, 210].
-99 <= Node.val <= 99
The depth of the tree will be in the range [1, 10].
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct Node {
    TreeNode *node;
    int c;
    Node() : c(0), node(nullptr) {}
    Node(TreeNode* n, int x) : node(n), c(x) {}
};

class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int height = depth(root);
        return bfs(root, height);

    }

    vector<vector<string>> bfs(TreeNode* root, int height) {
        int m = height + 1;
        int n = std::pow(2, m) - 1;
        vector<vector<string> > ans(m, vector<string>(n, ""));
        ans[0][(n-1)/2] = std::to_string(root->val);
        int r = 0;

        std::queue<Node*> q;
        q.push(new Node(root, (n-1)/2));
        int size = q.size();
        while (!q.empty()) {
            for (int i = 0; i < size; i++) {
                Node* n = q.front();
                q.pop();
                int interval = std::pow(2, height-r-1);
                if (n->node->left != nullptr) {
                    int c = n->c - interval;
                    ans[r+1][c] = std::to_string(n->node->left->val);
                    q.push(new Node(n->node->left, c));
                }
                if (n->node->right != nullptr) {
                    int c = n->c + interval;
                    ans[r+1][c] = std::to_string(n->node->right->val);
                    q.push(new Node(n->node->right, c));
                }
            }
            r++;
            size = q.size();
        }

        return ans;
    }

    int depth(TreeNode* root) {
        if (root == nullptr) {
            return -1;
        }
        return std::max(depth(root->left), depth(root->right)) + 1;
    }
};
