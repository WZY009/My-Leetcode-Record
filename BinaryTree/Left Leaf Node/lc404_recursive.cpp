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
public: int sum = 0;
public:
    int sumOfLeftLeaves(TreeNode* root) {
        //the most important thing is to judge whether it is left leaf.
        //the condition is: the node's left is not null and the node's left's left is null and the node's left's right is also null
        int sum = 0;
        Sum(root, &sum);
        return sum;

    }
    void Sum(TreeNode* root, int* sum) {
        int temp = *sum;
        if (root != nullptr) {
            int tempNode = root->val;
            if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) {
                *sum += root->left->val;
                Sum(root->right, sum);
            }
            else if (root->left == nullptr && root->right == nullptr) return;
            else {
                Sum(root->left, sum);
                Sum(root->right, sum);
            }
        }
        return;
    }
};


