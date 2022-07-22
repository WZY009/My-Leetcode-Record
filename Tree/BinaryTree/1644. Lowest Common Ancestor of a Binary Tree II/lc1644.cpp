/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * 
 * };
 */
class Solution {
public:
    bool pExist = false;
    bool qExist = false;
    
    TreeNode* find(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return root;
        
        TreeNode* left = find(root->left, p, q);
        TreeNode* right = find(root->right, p, q);
        
        if(left != nullptr && right != nullptr) return root;
        
        if(root == p || root == q) {
            if(root == p) pExist = true;
            if(root == q) qExist = true;
            return root;
        }
        
        return left != nullptr ? left : right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = find(root, p, q);
        if(pExist == true && qExist == true) return res;
        else return nullptr;
    }
};