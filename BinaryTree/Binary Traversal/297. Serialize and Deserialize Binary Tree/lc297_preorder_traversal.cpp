// 2022 5.18 20:54 - fail to slove this problem
// 2022 5.18 12:57 - After viewing the answer.  -- DFS

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
    void rserialize(TreeNode* root, string& s) {
        if(root == nullptr) {
            s += "null,";
            return;
        }
        s += to_string(root->val) + ',';
        rserialize(root->left, s);
        rserialize(root->right, s);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        rserialize(root, s);
        return s;
    }
    TreeNode* rdeserialize(list<string>& myList) {
        if(myList.front() == "null"){
            myList.pop_front();
            return nullptr;
        } 
        TreeNode* root = new TreeNode(stoi(myList.front()));
        myList.pop_front();
        root->left = rdeserialize(myList);
        root->right = rdeserialize(myList);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        list<string> myList;
        stringstream X(data);
        string temp;
        while(getline(X, temp, ',')) {
            myList.push_back(temp);
        }
        return rdeserialize(myList);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));