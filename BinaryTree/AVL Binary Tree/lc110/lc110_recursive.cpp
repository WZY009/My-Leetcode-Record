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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        else if (abs(Height(root->left) - Height(root->right)) > 1) return false;
        else {
            bool leftBalanced = isBalanced(root->left);
            bool rightBalanced = isBalanced(root->right);
            return leftBalanced && rightBalanced;
        }
    }
    int Height(TreeNode* root) {
        if (root == nullptr) return 0;
        else return max(Height(root->left), Height(root->right)) + 1;
    }
};