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
    int rob(TreeNode* root) {
        vector<int> vec = robTree(root);
        return max(vec[0],vec[1]);
    }
    vector<int> robTree(TreeNode* root) { // the array record the maximun of not-stealing and stealing this node!
        if(root == nullptr) return vector<int>{0, 0};
        vector<int> left = robTree(root->left);
        vector<int> right = robTree(root->right);
        int val1 = root->val + left[0] + right[0];
        int val2 = max(left[0], left[1]) + max(right[0], right[1]);
        return vector<int>{val2, val1};
    }
};