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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        int max = findMax(nums);
        TreeNode* root = new TreeNode(max);
        int maxPos = -1;
        for (int i = 0; i < nums.size(); i++)
            if (max == nums[i]) maxPos = i;
        vector<int> left(nums.begin(), nums.begin() + maxPos);
        vector<int> right(nums.begin() + maxPos + 1, nums.end());
        root->left = constructMaximumBinaryTree(left);
        root->right = constructMaximumBinaryTree(right);
        return root;
    }
    int findMax(vector<int>& num) {
        if (num.empty())  return INT_MIN;
        else
        {
            int max = num[0];
            for (int i = 0; i < num.size(); i++) if (num[i] > max) max = num[i];
            return max;
        }

    }
};