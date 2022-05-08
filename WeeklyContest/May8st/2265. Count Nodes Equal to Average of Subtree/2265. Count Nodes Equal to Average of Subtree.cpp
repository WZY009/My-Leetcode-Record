// 2265. Count Nodes Equal to Average of Subtree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    int result;
    pair<int, int> traversal(TreeNode* root) {
        if (root == nullptr) return { 0, 0 };
        pair<int, int> leftPair = traversal(root->left);
        pair<int, int> rightPair = traversal(root->right);
        int allSum = leftPair.first + rightPair.first + root->val;
        int allNum = leftPair.second + rightPair.second + 1;
        if (allSum / allNum == root->val) result++;
        return { allSum, allNum };
    }
    int averageOfSubtree(TreeNode* root) {

        pair<int, int> temp = traversal(root);
        return result;
    }
};
