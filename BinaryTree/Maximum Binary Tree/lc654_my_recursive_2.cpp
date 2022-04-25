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
    typedef pair<int, int> Max;
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        else {
            TreeNode* root = traversal(nums, 0, nums.size());
            return root;
        }
    }
    Max findMax(vector<int>& num, int begin, int end) {
        int max = num[begin];
        int i = begin;
        Max maxPair(i, max);
        for (; i < end; i++) {
            if (num[i] > max) {
                max = num[i];
                maxPair.second = max;
                maxPair.first = i;
            }
        }

        return maxPair;
    }
    TreeNode* traversal(vector<int>& nums, int begin, int end) {
        if (begin == end - 1) {
            TreeNode* root = new TreeNode(nums[begin]);
            return root;
        }
        else if (begin == end) {
            return nullptr;
        }
        else {
            Max maximum = findMax(nums, begin, end);
            TreeNode* root = new TreeNode(maximum.second);
            root->left = traversal(nums, begin, maximum.first);
            root->right = traversal(nums, maximum.first + 1, end);
            return root;
        }

    }
};

