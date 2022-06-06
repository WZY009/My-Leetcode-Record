// 2022 6.4 22：23 ~ 22:43 (用queue做效率太低！)

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
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<TreeNode*> que;
        que.push(root);
        int height = 0;
        while(!que.empty()) {
            height++;
            int size = que.size();
            TreeNode* temp;
            for(int i = 0; i < size; i++) {
                temp = que.front();
                que.pop();
                if(temp->left == nullptr && temp->right == nullptr) return height; // when you find the minimum height, you can return it immediately.
                if(temp->left != nullptr) que.push(temp->left);
                if(temp->right != nullptr) que.push(temp->right);
            }
        }
        return height;
    }
};