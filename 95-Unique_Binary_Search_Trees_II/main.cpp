/**
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

Example:

Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return vector<TreeNode*>();
        }
        vector<vector<TreeNode*>> dp(n);
        dp[0].push_back(new TreeNode(1));
        for (int i = 2; i <= n; i++) {
            for (auto pren : dp[i-2]) {
                TreeNode *nn = new TreeNode(i);
                nn->left = deepCopy(pren);
                dp[i-1].push_back(nn);

                TreeNode *t = pren;
                while (t) {
                    TreeNode *nn = new TreeNode(i);
                    TreeNode *tr = t->right;
                    nn->left = tr;
                    t->right = nn;
                    dp[i-1].push_back(deepCopy(pren));
                    t->right = tr;
                    t = tr;
                }
            }
        }
        return dp[n-1];
    }
    TreeNode* deepCopy(TreeNode* n) {
        if (n == nullptr) {
            return nullptr;
        }
        TreeNode* t = new TreeNode(n->val);
        t->left = deepCopy(n->left);
        t->right = deepCopy(n->right);
        return t;
    }
};
