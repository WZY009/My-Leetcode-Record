// 2022 5.21 17：53
// 2022 5.21 18:05 - Sloved! 
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
    int val;
    void traversal(TreeNode* root, int& k) {
        if(root == nullptr) return;
        traversal(root->left, k);
        k--;
        if(k == 0) val = root->val;
        traversal(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        traversal(root, k);
        return val;
    }
};