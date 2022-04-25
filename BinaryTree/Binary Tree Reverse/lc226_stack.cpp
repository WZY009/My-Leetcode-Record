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
        stack<TreeNode*> st;
        if (root != nullptr) st.push(root);
        TreeNode* curNode = nullptr;
        while (!st.empty()) {
            curNode = st.top();
            st.pop();
            swap(curNode->left, curNode->right);
            if (curNode->right != nullptr) st.push(curNode->right);
            if (curNode->left != nullptr) st.push(curNode->left);
        }
        return root;
    }
};