// 2022 5.24 14:09 ~ 14:12(Paused for bathroom)
// 2022 5.24 14:42 - (Unsolved)
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
class Solution
{
public:
    vector<TreeNode *> generate(int lo, int hi)
    {
        vector<TreeNode *> vec;
        if (lo > hi)
        { // Pay attention! you can't use larger or equal !!!
            vec.push_back(nullptr);
            return vec;
        }
        // list all possible result
        for (int i = lo; i <= hi; i++)
        {
            vector<TreeNode *> lefts = generate(lo, i - 1);  // generate all possible left child trees
            vector<TreeNode *> rights = generate(i + 1, hi); // generate all possible right child trees
            for (auto left : lefts)
            {
                for (auto right : rights)
                {
                    TreeNode *root = new TreeNode(i); // this line can not be in front of right loops!
                    root->left = left;
                    root->right = right;
                    vec.push_back(root);
                }
            }
        }
        return vec;
    }
    vector<TreeNode *> generateTrees(int n)
    {
        return generate(1, n);
    }
};