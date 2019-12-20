/**
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return isSymmetric(root->left, root->right);
    }
    bool isSymmetric(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) {
            return true;
        }
        if (left == nullptr || right == nullptr) {
            return false;
        }
        return (left->val == right->val) && isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
};

/**
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return true;
        }
        if (root->left == nullptr || root->right == nullptr) {
            return false;
        }
        if (root->left->val != root->right->val) {
            return false;
        }
        stack<TreeNode*> st;
        st.push(root->right);
        st.push(root->left);
        TreeNode *left, *right;
        while (!st.empty()) {
            if (st.size() % 2 != 0) {
                return false;
            }
            left = st.top();
            st.pop();
            right = st.top();
            st.pop();
            if (left->val != right->val) {
                return false;
            }
            if (left->left == nullptr && right->right != nullptr) {
                return false;
            }
            if (left->left != nullptr && right->right == nullptr) {
                return false;
            }
            if (left->left != nullptr && right->right != nullptr) {
                if (left->left->val != right->right->val) {
                    return false;
                }
                st.push(right->right);
                st.push(left->left);
            }
            
            if (left->right == nullptr && right->left != nullptr) {
                return false;
            }
            if (left->right != nullptr && right->left == nullptr) {
                return false;
            }
            if (left->right != nullptr && right->left != nullptr) {
                if (left->right->val != right->left->val) {
                    return false;
                }
                st.push(right->left);
                st.push(left->right);
            }
        }
        return true;
    }
};
 */
