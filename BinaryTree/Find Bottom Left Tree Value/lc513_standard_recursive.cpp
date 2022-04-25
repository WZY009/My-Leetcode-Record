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
    int maxLen = INT_MIN;
    int maxLeftValue;
    void traversal(TreeNode* root, int depth) {
        if (root != nullptr) {
            if (root->left == nullptr && root->right == nullptr) {
                if (maxLen < depth) {
                    maxLeftValue = root->val;
                    maxLen = depth;
                }
            }
            depth++;
            traversal(root->left, depth);
            depth--;
            depth++;
            traversal(root->right, depth);
            depth--;
        }
        return;
    }
    int findBottomLeftValue(TreeNode* root) {
        traversal(root, 0);
        return maxLeftValue;
    }


};
