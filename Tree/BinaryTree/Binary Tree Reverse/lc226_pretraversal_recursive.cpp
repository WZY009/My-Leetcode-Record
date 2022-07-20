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
    TreeNode* invertTree(TreeNode* root) {
        if (root != nullptr) {
            swap(root->left, root->right);
            traversal(root->left);
            traversal(root->right);
        }
        return root;
    }
    void traversal(TreeNode* root) {
        if (root != nullptr) {
            swap(root->left, root->right);
            traversal(root->left);
            traversal(root->right);
        }
        return;
    }
};