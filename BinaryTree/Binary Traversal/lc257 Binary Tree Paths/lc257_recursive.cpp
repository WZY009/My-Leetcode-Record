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
    vector<string> binaryTreePaths(TreeNode* root) {
        string temp;
        vector<string> vec;
        temp.append(to_string(root->val));
        path(root, &temp, &vec);
        return vec;

    }
    void path(TreeNode* root, string* str, vector<string>* vec) {
        if (root->left == nullptr && root->right == nullptr) {
            vec->push_back(*str);
            return;
        }
        else if (root->left != nullptr && root->right == nullptr) {
            addNode(root->left, str);
            path(root->left, str, vec);
        }
        else if (root->left == nullptr && root->right != nullptr) {
            addNode(root->right, str);
            path(root->right, str, vec);
        }
        else {
            string temp = *str;
            addNode(root->left, str);
            path(root->left, str, vec);
            addNode(root->right, &temp);
            path(root->right, &temp, vec);
        }
        return;
    }
    void addNode(TreeNode* node, string* str) {
        str->append("-");
        str->append(">");
        str->append(to_string(node->val));
    }
};