//2022 5.18 20：40 - forget Morris traversal
// 2022 5.18 20:55 - Viewing the answer
// 2022 5.18 21:03 - finishing the answer
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
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        
        TreeNode* leftNode = root->left;
        TreeNode* rightNode = root->right;
        root->left = nullptr;
        root->right = leftNode;
        TreeNode* p = root;
        while(p->right != nullptr) p = p->right;
        p->right = rightNode;
        
        flatten(root->left);
        flatten(root->right);
    }
};