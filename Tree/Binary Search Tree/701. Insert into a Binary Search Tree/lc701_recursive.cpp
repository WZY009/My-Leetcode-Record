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
        else {
            traversal(root, val);
            return root;
        }
    }
    void traversal(TreeNode* root, int val) {
        if (root->left == nullptr && val < root->val) {
            root->left = new TreeNode(val);
            return;
        }
        else if (root->right == nullptr && val > root->val) {
            root->right = new TreeNode(val);
            return;
        }
        else {
            if (val < root->val) traversal(root->left, val);
            else traversal(root->right, val);
            return;
        }
    }
};

