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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            TreeNode* temp = new TreeNode(val);
            return temp;
        }
        TreeNode* curNode = root;
        TreeNode* pre = root;
        while (curNode != nullptr) {
            pre = curNode;
            curNode = val < curNode->val ? curNode->left : curNode->right;
        }
        TreeNode* newNode = new TreeNode(val);
        if (val < pre->val) pre->left = newNode;
        else pre->right = newNode;
        return root;
    }
};

