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
class Solution {
public:
    Solution() {
        i = 1;
        val = 0;
    }
    int kthSmallest(TreeNode* root, int k) {
        find(root, k);
        return val;
    }
    void find(TreeNode* root, int &k) {
        if (root) {
            find(root->left, k);
            if (i == k) {
                val = root->val;
                k = 0;
                return;
            }
            i += 1;
            find(root->right, k);
        }
    }

private:
    int i;
    int val;
};
