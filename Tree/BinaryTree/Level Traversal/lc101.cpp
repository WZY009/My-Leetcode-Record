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
    bool isSymmetric(TreeNode* root) {
        queue <TreeNode*> que;
        if (root != nullptr) que.push(root);
        TreeNode* curNode = nullptr;
        while (!que.empty()) {
            vector<TreeNode*> vec;
            int size = que.size();
            for (int i = 0; i < size; i++) {
                curNode = que.front();
                que.pop();
                vec.push_back(curNode);
                if (curNode != nullptr) {
                    if (curNode->left != nullptr) que.push(curNode->left);
                    else que.push(nullptr);
                    if (curNode->right != nullptr) que.push(curNode->right);
                    else que.push(nullptr);
                }
            }
            for (int i = 0, j = size - 1; i < j; i++, j--) {
                if (vec[i] == nullptr) {
                    if (vec[j] != nullptr)
                        return false;
                }
                else if (vec[j] == nullptr) {
                    if (vec[i] != nullptr)
                        return false;
                }
                else if (vec[i]->val != vec[j]->val)
                    return false;
            }
        }
        return true;
    }
};
