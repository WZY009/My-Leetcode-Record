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
    bool isValidBST(TreeNode* root) {
        if (root != nullptr) {
            if (!isSmaller(root->left, root->val)) return false;
            if (!isLarger(root->right, root->val)) return false;
            bool leftResult = isValidBST(root->left);
            bool rightResult = isValidBST(root->right);
            return leftResult && rightResult;
        }
        return true;
    }
    bool isLarger(TreeNode* root, int val) {
        if (root != nullptr)
            return (root->val > val) && isLarger(root->left, val) && isLarger(root->right, val);
        else return true;
    }
    bool isSmaller(TreeNode* root, int val) {
        if (root == nullptr)
            return true;
        else return(root->val < val) && isSmaller(root->left, val) && isSmaller(root->right, val);
    }
};