// 2022 5.18 22:31
// 2022 5.18 22:51 暂停
// 2022 5.18 20:32 - AC - The most important part is controlling the boarder condition!
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
    TreeNode* build(vector<int>& preorder, vector<int>& postorder, int leftPre, int rightPre, int leftPost, int rightPost) {
        if(leftPre < 0 || rightPre >= preorder.size() || leftPost < 0 || rightPost >= postorder.size() || leftPre > rightPre || leftPost > rightPost) return nullptr;
        TreeNode* root = new TreeNode(preorder[leftPre]);
        if(leftPre + 1 > rightPre) return root;
        int LTsize = -1;
        int RTsize = -1;
        int patition = -1;
        for(int i = leftPost; i <= rightPost; i++) {
            if(preorder[leftPre + 1] == postorder[i])  {
                patition = i;
                LTsize = i - leftPost + 1; // include the left node
                RTsize = rightPost - i - 1; // pay attention! you have to get rid of the root node
                break;
            }
        }
        root->left = build(preorder, postorder, leftPre + 1, leftPre + LTsize, leftPost, patition);
        root->right = build(preorder, postorder, leftPre + LTsize + 1, rightPre, patition + 1, rightPost - 1);
        return root;
    } 
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return build(preorder, postorder, 0, preorder.size() - 1, 0, postorder.size() - 1);
    }
};