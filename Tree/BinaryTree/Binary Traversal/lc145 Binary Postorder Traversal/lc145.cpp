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
    void traversal(TreeNode* root, vector<int>* result) {
        if (root != nullptr) {
            traversal(root->left, result);
            traversal(root->right, result);
            result->push_back(root->val);
        }
        return;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root != nullptr) {//you have to add this kind of check condition!
            if (root->left != nullptr)  traversal(root->left, &result);
            if (root->right != nullptr) traversal(root->right, &result);
            result.push_back(root->val);
        }

        return result;
    }

};
