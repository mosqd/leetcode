/**
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }
        std::queue<TreeNode*> q;
        q.push(root);
        int i = 0;
        int cur = 0;
        TreeNode* n = nullptr;
        while (!q.empty()) {
            cur = q.size();
            vector<int> v(cur, 0);
            i = 0;
            while (cur > 0) {
                n = q.front();
                q.pop();
                v[i] = n->val;
                i++;
                cur--;
                if (n->left) {
                    q.push(n->left);
                }
                if (n->right) {
                    q.push(n->right);
                }
            }
            ans.push_back(std::move(v));
        }
        return ans;
    }
};
