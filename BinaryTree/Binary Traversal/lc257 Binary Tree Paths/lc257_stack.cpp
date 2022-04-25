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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        stack<string> stPath; stack<TreeNode*> stTree;
        stPath.push(to_string(root->val)); stTree.push(root);
        TreeNode* curNode;
        string  curPath;
        while (!stTree.empty()) {
            curNode = stTree.top(); stTree.pop();
            curPath = stPath.top(); stPath.pop();
            if (curNode->left == nullptr && curNode->right == nullptr) {
                result.push_back(curPath);
            }
            if (curNode->right != nullptr) {
                stTree.push(curNode->right);
                stPath.push(curPath + "->" + to_string(curNode->right->val));
            }
            if (curNode->left != nullptr) {
                stTree.push(curNode->left);
                stPath.push(curPath + "->" + to_string(curNode->left->val));
            }
        }
        return result;
    }
};
