// 2022 5.18 21:37
// 2022 5.18 22:17 - Your efficiency is too low !!!!!!
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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int leftPre, int rightPre, int leftIn, int rightIn) {
        if(leftPre < 0 || rightIn < 0 || rightPre > preorder.size() - 1 || rightIn > inorder.size() - 1 || leftPre > rightPre || leftIn > rightIn) 
            return nullptr;
        TreeNode* root = new TreeNode(preorder[leftPre]);
        int LTsize = -1;
        int RTsize = -1;
        int mid = -1;
        for(int i = leftIn; i <= rightIn; i++) {
            if(inorder[i] == preorder[leftPre]) {
                LTsize = i - leftIn + 1;
                RTsize = rightIn - i + 1;
                mid = i;
            }
        }
        root->left = build(preorder, inorder, leftPre + 1, leftPre + LTsize - 1, leftIn, mid - 1);
        root->right = build(preorder, inorder, leftPre + LTsize, rightPre, mid + 1, rightIn);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};