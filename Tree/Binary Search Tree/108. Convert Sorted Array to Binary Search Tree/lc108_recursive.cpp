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
    TreeNode* sortedArrayToBST(vector<int>& nums) {//pay attention! the right side can not be used.
        int left = 0;
        int right = nums.size();
        return buildBST(nums, left, right);
    }
    TreeNode* buildBST(vector<int>& nums, int left, int right) {
        if (right == left) return nullptr;
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        TreeNode* leftTree = buildBST(nums, left, mid);
        TreeNode* rightTree = buildBST(nums, mid + 1, right);
        root->left = leftTree;
        root->right = rightTree;
        return root;
    }
};

