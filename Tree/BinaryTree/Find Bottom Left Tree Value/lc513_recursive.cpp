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
    int findBottomLeftValue(TreeNode* root) {
        if (root != nullptr) {
            if (root->left == nullptr && root->right == nullptr)
                return root->val;
            if (Height(root->left) < Height(root->right)) {
                return findBottomLeftValue(root->right);
            }
            else
                return findBottomLeftValue(root->left);
        }
        else return 0;

    }
    int Height(TreeNode* root) {
        if (root == nullptr) return 0;
        else return 1 + max(Height(root->left), Height(root->right));
    }

};
