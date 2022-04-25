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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != nullptr) que.push(root);
        TreeNode* curNode = nullptr;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                curNode = que.front();
                que.pop();
                swap(curNode->left, curNode->right);
                if (curNode->left != nullptr) que.push(curNode->left);
                if (curNode->right != nullptr) que.push(curNode->right);
            }
        }
        return root;
    }
};