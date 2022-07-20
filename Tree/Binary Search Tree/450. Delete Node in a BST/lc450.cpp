// 2022 5.23 11:46 ~ 12:10 (Unsolved!!!)
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
    // 1. find the node whose one of child is key node.
    // 2. let the key node's non - empty replace the original place.
    // 3. according what you choose, move the other one

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return root;
        if(root->val < key){
            root->right = deleteNode(root->right, key);
            return root;
        } else if(root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        } else { 
            // root->val == key
            // the following two lines contain the situation that the target node is leaf node
            if(root->right == nullptr) return root->left;
            else if(root->left == nullptr) return root->right;
            else {
                // the target node is not leaf node and it has two children    
                // find the most left node in the right child tree
                TreeNode* cur = root->right; 
                while(cur->left != nullptr) cur = cur->left;
                cur->left = root->left;
                return root->right;
            }
        }
        
    }
};