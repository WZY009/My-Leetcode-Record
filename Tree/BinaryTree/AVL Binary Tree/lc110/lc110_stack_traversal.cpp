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
private:
    int Height(TreeNode* cur) {
        stack<TreeNode*> st;
        if (cur != NULL) st.push(cur);
        int depth = 0; // 记录深度
        int result = 0;
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != NULL) {
                st.pop();
                st.push(node); // 中
                st.push(NULL);
                depth++;
                if (node->right) st.push(node->right); // 右
                if (node->left) st.push(node->left); // 左
            }
            else {
                st.pop();
                node = st.top();
                st.pop();
                depth--;
            }
            result = max(result, depth);
        }
        return result;
    }
};
