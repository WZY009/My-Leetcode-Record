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
        return traversal(root, targetSum);
    }
    bool traversal(TreeNode* root, int count) {
        if (root != nullptr) {
            count -= root->val;
            if (root->left == nullptr && root->right == nullptr && count == 0) {
                return true;
            }
            else
            {
                bool isLeft = traversal(root->left, count);
                bool isRight = traversal(root->right, count);
                return isLeft || isRight;
            }
        }
        else
            return false;
    }
};