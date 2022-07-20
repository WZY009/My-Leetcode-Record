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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == nullptr) return root;
        while (root != nullptr) {
            if (root->val < low) {
                root = root->right;
                continue;
            }
            else if (root->val > high) {
                root = root->left;
                continue;
            }
            else
                break;
        }
        TreeNode* curNode = root;
        if (root == nullptr) return root;

        while (curNode->left != nullptr) {
            if (curNode->left->val < low) {
                curNode->left = curNode->left->right;
                continue;
            }
            curNode = curNode->left;
        }
        if (curNode->left != nullptr && curNode->left->val < low)
            curNode = nullptr;
        curNode = root;
        while (curNode->right != nullptr) {
            if (curNode->right->val > high) {
                curNode->right = curNode->right->left;
                continue;
            }
            curNode = curNode->right;
        }
        if (curNode->right != nullptr && curNode->right->val > high)
            curNode = nullptr;

        return root;
    }
};

