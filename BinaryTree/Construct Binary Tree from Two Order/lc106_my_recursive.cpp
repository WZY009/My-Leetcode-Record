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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0) return nullptr;
        int rootValue = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(rootValue);
        int rootPos = -1;
        for (int i = 0; i < inorder.size(); i++) {
            if (rootValue == inorder[i]) {
                rootPos = i;
                break;
            }
        }
        vector<int> leftInorder(inorder.begin(), inorder.begin() + rootPos);
        vector<int> rightInorder(inorder.begin() + rootPos + 1, inorder.end());
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + rootPos);
        vector<int> rightPostorder(postorder.begin() + rootPos, postorder.end() - 1);
        root->left = buildTree(leftInorder, leftPostorder);
        root->right = buildTree(rightInorder, rightPostorder);
        return root;
    }
};


