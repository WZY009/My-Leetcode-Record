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
    bool hasPathSum(TreeNode* root, int targetSum) {
        stack<TreeNode*> stNode;
        stack<int> stSum;
        TreeNode* curNode;
        if (root != nullptr) {
            stNode.push(root);
            stSum.push(targetSum);
        }
        while (!stNode.empty()) {
            curNode = stNode.top();  stNode.pop();
            int curSum = stSum.top() - curNode->val; stSum.pop();
            if (curNode->left == nullptr && curNode->right == nullptr && curSum == 0) return true;
            if (curNode->left == nullptr && curNode->right == nullptr && curSum != 0) continue;
            if (curNode->right != nullptr) {
                stNode.push(curNode->right);
                stSum.push(curSum);
            }
            if (curNode->left != nullptr) {
                stNode.push(curNode->left);
                stSum.push(curSum);
            }

        }
        return false;
    }
};

