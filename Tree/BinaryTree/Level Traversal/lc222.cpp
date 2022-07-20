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
        queue<TreeNode*> que;
        if (root != nullptr) que.push(root);
        int num = 0;
        while (!que.empty()) {
            TreeNode* curNode = que.front();
            que.pop();
            num++;
            if (curNode->left != nullptr) que.push(curNode->left);
            if (curNode->right != nullptr) que.push(curNode->right);
        }
        return num;
    }
};

