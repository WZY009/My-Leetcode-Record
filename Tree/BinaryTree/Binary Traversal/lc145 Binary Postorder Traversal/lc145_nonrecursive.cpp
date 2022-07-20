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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        stack<int> stNum;
        if (root == nullptr)  return result;
        TreeNode* curNode = root;
        st.push(curNode);
        while (!st.empty()) {
            curNode = st.top();
            st.pop();
            stNum.push(curNode->val);
            if (curNode->left != nullptr) st.push(curNode->left);//pay attention to the order of stack input!
            if (curNode->right != nullptr) st.push(curNode->right);
        }
        while (!stNum.empty()) {
            result.push_back(stNum.top());
            stNum.pop();
        }
        return result;
    }

};
