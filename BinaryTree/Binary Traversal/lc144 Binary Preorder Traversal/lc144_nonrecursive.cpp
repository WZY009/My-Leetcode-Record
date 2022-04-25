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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* curNode = root;
        if (root == nullptr) return result;
        st.push(curNode);
        while (!st.empty()) {
            curNode = st.top();
            st.pop();
            result.push_back(curNode->val);
            if (curNode->right != nullptr) st.push(curNode->right);
            if (curNode->left != nullptr) st.push(curNode->left);
        }
        return result;
    }
};
