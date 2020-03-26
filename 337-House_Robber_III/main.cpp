/**
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:

Input: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

Output: 7 
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:

Input: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1

Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
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
    int rob(TreeNode* root) {
        auto money = robHelper(root);
        return max(money.first, money.second);
    }
    std::pair<int, int> robHelper(TreeNode* root) {
        if (root == nullptr) return make_pair(0, 0);

        auto left = robHelper(root->left);
        auto right = robHelper(root->right);
        auto money = make_pair(0, 0);
        money.first = left.second + right.second + root->val;
        money.second = std::max(left.first, left.second) + std::max(right.first, right.second);
        return money;
    }
};

/**
class Solution {
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> m;
        return rob(root, m);
    }
    int rob(TreeNode* root, unordered_map<TreeNode*, int>& m) {
        if (root == nullptr) return 0;
        if (m.find(root) != m.end()) {
            return m[root];
        }
        int money = 0;
        if (root->left) {
            money += rob(root->left->left, m) + rob(root->left->right, m);
        }
        if (root->right) {
            money += rob(root->right->left, m) + rob(root->right->right, m);
        }
        money = std::max(money+root->val, rob(root->left, m)+rob(root->right, m));
        m[root] = money;
        return money;
    }
};
*/
