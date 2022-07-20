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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        else if (abs(Height(root->left) - Height(root->right)) > 1) return false;
        else {
            bool leftBalanced = isBalanced(root->left);
            bool rightBalanced = isBalanced(root->right);
            return leftBalanced && rightBalanced;
        }
    }
    int Height(TreeNode* root) {
        queue<TreeNode*> que;
        int height = 0;
        if (root != nullptr) que.push(root);
        TreeNode* curNode;
        while (!que.empty()) {
            vector<TreeNode*> vec;
            while (!que.empty()) {
                vec.push_back(que.front());
                que.pop();
            }
            int size = vec.size();
            for (int i = 0; i < size; i++) {
                if (vec[i]->left != nullptr) que.push(vec[i]->left);
                if (vec[i]->right != nullptr) que.push(vec[i]->right);
            }
            height++;
        }
        return height;
    }
};
