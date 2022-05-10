// 2022 5.10 19:55 ~ 19：57(have a idea)
// 2022 5.10 20:02
// This method is not very good! because it's time complexity is O(n ^ 2)
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
class Solution
{
public:
    int getHeight(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        int res = max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right));
        return res > left + right ? res : left + right;
    }
};