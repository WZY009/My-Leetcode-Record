// 2022 5.10 21:22 ~ 21:28(think of an idea) -
// 2022 5.10 21：43 （没做出来）
// 2022 5.10 21：55 (after reviewing the answer)
// 2022 5.10 21：57 

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
    void traversal(TreeNode* root) {
        if(root == nullptr) return;
        swap(root->left, root->right);
        traversal(root->left);
        traversal(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return nullptr;
        traversal(root);
        return root;
    }
};