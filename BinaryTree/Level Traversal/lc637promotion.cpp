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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> que;
        vector<double> result;
        if (root != nullptr) que.push(root);
        while (!que.empty()) {
            double sum = 0.0;
            double avg = 0.0;
            int size = que.size();
            TreeNode* curNode;
            for (int i = 0; i < size; i++) {
                curNode = que.front();
                que.pop();
                sum += curNode->val;
                if (curNode->left != nullptr) que.push(curNode->left);
                if (curNode->right != nullptr) que.push(curNode->right);
            }
            avg = sum / size;
            result.push_back(avg);
        }
        return result;
    }
};