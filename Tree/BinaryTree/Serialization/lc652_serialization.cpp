// 2022 5.20 14：27 ~ 14：52 - can't slove it!
// 2022 5.20 15:00 - viewing the answer
// 2022 5.20 18:00 - Coming back!
// 2022 5.20 19:48 
// The key of this question is serilization 
// A preorder or postorder series (null subtrees should also be included) can define a tree
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
    string serialize(TreeNode* root, unordered_map<string, int>& umap, vector<TreeNode*>& result) {
        if(root == nullptr) return "#";
        string left = serialize(root->left, umap, result);
        string right = serialize(root->right, umap, result);
        string subTree = to_string(root->val) + ',' + left +',' + right;
        //string subTree = left + ',' + to_string(root->val) + ',' + right; // The serialized binary tree may have ambiguit in this way. 
        if(umap[subTree] == 1) result.push_back(root);
        umap[subTree]++;
        return subTree;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> umap;
        vector<TreeNode*> result;
        serialize(root, umap, result);
        return result;
    }
};