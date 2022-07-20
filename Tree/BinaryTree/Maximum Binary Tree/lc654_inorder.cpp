// 2022 5.18 21:15
// 2022 5.18 21:26
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
    TreeNode* traversal(vector<int>& nums, int left, int right) {
        if(left < 0 || right > nums.size() - 1 || left > right) return nullptr;
        int maxPos = -1;
        int maxNum = INT_MIN;
        for(int i = left; i <= right; i++) {
            if(nums[i] > maxNum) {
                maxPos = i;
                maxNum = nums[i];
            }
        }
        TreeNode* root = new TreeNode(maxNum);
        root->left = traversal(nums, left, maxPos - 1);
        root->right = traversal(nums, maxPos + 1, right);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return traversal(nums, 0, nums.size() - 1);
    }
};