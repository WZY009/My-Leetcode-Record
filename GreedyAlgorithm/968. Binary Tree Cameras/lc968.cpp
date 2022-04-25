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
// post-traversal!
class Solution {
public:
    int result;
    int traversal(TreeNode* root) {
        if(root == nullptr) return 2; // null means it has been covered!
        int left = traversal(root->left);
        int right = traversal(root->right);
        if(left == 2 && right == 2) return 0; // the left and right child have been covered. so the node can not be covered!
        if(left == 0 || right == 0) {
            result++; // there is at least one node that hasn't been covered yet.
            return 1;
        }
        if(left == 1 || right == 1) {
            return 2; // the node has been covered
        }
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        result = 0;
        if(traversal(root) == 0) result++;
        return result;
    }
};