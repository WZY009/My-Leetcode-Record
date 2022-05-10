// 2022 5.10 19:55 ~ 19：57(have a idea)
// 2022 5.10 20:02
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
    int getHeight(TreeNode* root, int& maximum) {
        if(root == nullptr) return 0;
        int left = getHeight(root->left, maximum);
        int right = getHeight(root->right, maximum);
        int myMax = left + right;
        maximum = max(myMax, maximum); // we update the answer in the getHeight() function we update it every time when we finish analyzing a node! 
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maximum = 0;
        int temp = getHeight(root, maximum); // temp is useless!
        return maximum;
    }
};