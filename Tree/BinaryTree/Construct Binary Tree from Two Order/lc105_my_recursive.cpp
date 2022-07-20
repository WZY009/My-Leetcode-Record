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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0) return nullptr;
        int rootValue = preorder[0];
        TreeNode* root = new TreeNode(rootValue);
        int rootPos = -1;
        for (int i = 0; i < inorder.size(); i++) {
            if (rootValue == inorder[i]) {
                rootPos = i;
                break;
            }
        }
        vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + rootPos + 1);
        vector<int> rightPreorder(preorder.begin() + rootPos + 1, preorder.end());
        vector<int> leftInorder(inorder.begin(), inorder.begin() + rootPos);
        vector<int> rightInorder(inorder.begin() + rootPos + 1, inorder.end());
        root->left = buildTree(leftPreorder, leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);
        return root;
    }
};