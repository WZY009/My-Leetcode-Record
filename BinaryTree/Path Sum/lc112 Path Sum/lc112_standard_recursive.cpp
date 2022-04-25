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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root != nullptr) return traversal(root, targetSum);
        else {
            return false;
        }
    }
    bool traversal(TreeNode* root, int count) {
        count -= root->val;
        if (root->left == nullptr && root->right == nullptr && count == 0) return true;
        else if (root->left == nullptr && root->right == nullptr && count != 0) return false;
        if (root->left != nullptr) {
            if (traversal(root->left, count) == true) return true;
        }
        if (root->right != nullptr) {
            if (traversal(root->right, count) == true) return true;
        }
        return false;
    }
};
