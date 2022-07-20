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

    TreeNode* convertBST(TreeNode* root) {
        stack<TreeNode*> st;
        int pre = 0;
        if (root == nullptr) return root;
        TreeNode* curNode = root;
        while (!st.empty() || curNode != nullptr) {
            if (curNode != nullptr) {
                st.push(curNode);
                curNode = curNode->right;
            }
            else {
                curNode = st.top(); st.pop();
                curNode->val += pre;
                pre = curNode->val;
                curNode = curNode->left;
            }
        }
        return root;
    }
};
