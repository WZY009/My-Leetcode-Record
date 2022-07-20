// 2022 5.19 20:54 - fail to slove this problem
// 2022 5.20 12:57 - After viewing the answer.  -- DFS
// 2022 5.20 13:16 - Viewing the answer for twice
// 2022 5.20 13:27 - Recursive descent
/* 
In computer science, recursive descent parser is a top-down parser, which is constructed by a group of mutually recursive programs (or equivalent non recursive programs), in which each program implements a non terminator in grammar. Therefore, the structure of these programs closely reflects the grammatical structure it recognizes.

*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) return "X";
        string left = '(' + serialize(root->left) + ')';
        string right = '(' + serialize(root->right) + ')';
        return left + to_string(root->val) + right;
    }
    TreeNode* parseSubTree(const string& s, int& ptr) {
        ptr++; // skip the left palindrome
        TreeNode* tree = parse(s, ptr);
        ptr++; // skip the right palindrome
        return tree;
    }
    int parseInt(const string& s, int& ptr) {
        int sign = 1;
        int res = 0;
        if(s[ptr] == '-') {
            sign = -1;
            ptr++;
        }
        while(isdigit(s[ptr])) {
            res = res * 10 + (int)s[ptr] - '0'; // pay attention! if '0' turn to int type. it will become 48
            ptr++;
        }
        return res * sign;
    }
    TreeNode* parse(const string& s, int& ptr) {
        if(s[ptr] == 'X') {
            ptr++;
            return nullptr;
        }
        TreeNode* root = new TreeNode(0);
        root->left = parseSubTree(s, ptr);
        root->val = parseInt(s, ptr);
        root->right = parseSubTree(s, ptr);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int ptr = 0;
        return parse(data, ptr);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));