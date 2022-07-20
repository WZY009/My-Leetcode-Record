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
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        return traversal(root, nodes, nodes.size() - 1);
    }
    TreeNode* traversal(TreeNode* root, vector<TreeNode*>& nodes, int end) {
        if(end == 0) return nodes[0];
        int index = 0;
        int i = 1;
        while(i <= end) {
            nodes[index++] = find(root, nodes[i - 1], nodes[i]);
            i += 2;
        }
        if(end % 2 == 0) { // the number of node is odd number 
            nodes[index] = nodes[end];
            return traversal(root, nodes, index); 
        } 
        else return traversal(root, nodes, index - 1); // the number of nodes is even number
    }
    TreeNode* find(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return root;
        if(root == p || root == q) return root;
        TreeNode* left = find(root->left, p, q);
        TreeNode* right = find(root->right, p, q);
        if(left != nullptr && right != nullptr) return root;
        return left != nullptr ? left : right;
    }
};