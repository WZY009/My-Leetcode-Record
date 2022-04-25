/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int minimum = min(p->val, q->val);
        int maximum = max(p->val, q->val);
        while (root) {
            if (root->val >= minimum && root->val <= maximum) return root;
            else if (root->val > maximum) root = root->left;
            else if (root->val < minimum)  root = root->right;
        }
        return nullptr;
    }
};
