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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> que;
        if (root != nullptr) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            TreeNode* curNode;
            for (int i = 0; i < size; i++) {
                curNode = que.front();
                que.pop();
                if (i == size - 1) result.push_back(curNode->val);
                if (curNode->left != nullptr) que.push(curNode->left);
                if (curNode->right != nullptr) que.push(curNode->right);
            }
        }
        return result;
    }
};