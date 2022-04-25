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
    vector<int> vec;
    int getMinimumDifference(TreeNode* root) {
        if (root != nullptr) traversal(root);
        int min = INT_MAX;
        for (int i = 0; i < vec.size() - 1; i++) {
            if (abs(vec[i] - vec[i + 1]) < min) min = abs(vec[i] - vec[i + 1]);
        }
        return min;
    }
    void traversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* curNode = root;
        while (curNode != nullptr || !st.empty()) {
            if (curNode != nullptr) {
                st.push(curNode);
                curNode = curNode->left;
            }
            else {
                curNode = st.top();
                st.pop();
                vec.push_back(curNode->val);
                curNode = curNode->right;
            }
        }
    }
};
