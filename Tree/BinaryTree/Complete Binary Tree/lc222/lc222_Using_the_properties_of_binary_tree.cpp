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
    int countNodes(TreeNode* root) {
        // the most important is to know how to determine whether a tree is perfect binary tree!
        if (root == nullptr) return 0;
        TreeNode* leftNode = root->left;
        TreeNode* rightNode = root->right;
        int leftHeight = 0, rightHeight = 0;
        while (leftNode != nullptr) {
            leftNode = leftNode->left;
            leftHeight++;
        }
        while (rightNode != nullptr) {
            rightNode = rightNode->right;
            rightHeight++;
        }
        if (rightHeight == leftHeight)  return (2 << leftHeight) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;

    }
};

