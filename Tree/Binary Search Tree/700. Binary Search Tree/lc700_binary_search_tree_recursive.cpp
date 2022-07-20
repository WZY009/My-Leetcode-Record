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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root != nullptr) {
            if (root->val == val) return root;
            else {
                TreeNode* result;
                if (root->val > val) {
                    result = searchBST(root->left, val);
                    return result;
                }
                else {
                    result = searchBST(root->right, val);
                    return result;
                }
            }
        }
        else return nullptr;

    }
};