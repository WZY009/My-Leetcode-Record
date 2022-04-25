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
    TreeNode* sortedArrayToBST(vector<int>& nums) {//pay attention! the right side can be used.
        //the key is that we should use three queues to record the tree states 
        if (nums.empty()) return nullptr;
        int left = 0;
        int right = nums.size() - 1;
        queue<TreeNode*> nodeQue;
        queue<int> leftQue, rightQue;
        TreeNode* root = new TreeNode();
        TreeNode* curNode;
        nodeQue.push(root);
        leftQue.push(left);
        rightQue.push(right);
        while (!nodeQue.empty()) {
            curNode = nodeQue.front();
            nodeQue.pop();
            left = leftQue.front(); leftQue.pop();
            right = rightQue.front(); rightQue.pop();
            int mid = left + (right - left) / 2;
            curNode->val = nums[mid];
            if (left <= mid - 1) {
                curNode->left = new TreeNode();
                nodeQue.push(curNode->left);
                leftQue.push(left);
                rightQue.push(mid - 1);
            }
            if (right >= mid + 1) {
                curNode->right = new TreeNode();
                nodeQue.push(curNode->right);
                leftQue.push(mid + 1);
                rightQue.push(right);
            }
        }
        return root;
    }

};

