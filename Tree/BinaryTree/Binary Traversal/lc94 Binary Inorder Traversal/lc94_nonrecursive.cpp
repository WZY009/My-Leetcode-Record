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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* mostLeftNode = root;
        TreeNode* curNode;
        while (!st.empty() || mostLeftNode != nullptr) {
            if (mostLeftNode != nullptr) {
                st.push(mostLeftNode);
                mostLeftNode = mostLeftNode->left;
            }
            else {
                mostLeftNode = st.top();
                st.pop();
                result.push_back(mostLeftNode->val);
                mostLeftNode = mostLeftNode->right;

            }
        }
        return result;
    }
};