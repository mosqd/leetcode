/**
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) {
            return nullptr;
        }
        return buildTree(preorder, 0, inorder, 0, inorder.size()-1);
    }
    TreeNode* buildTree(vector<int>& preorder, int index, vector<int>& inorder, int begin, int end) {
        if (end < begin || index == preorder.size()) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[index]);
        int p = begin;
        for (int i = begin; i <= end; i++) {
            if (inorder[i] == preorder[index]) {
                p = i;
                break;
            }
        }
        root->left = buildTree(preorder, index+1, inorder, begin, p-1);
        root->right = buildTree(preorder, index+p-begin+1, inorder, p+1, end);
        return root;
    }

};
