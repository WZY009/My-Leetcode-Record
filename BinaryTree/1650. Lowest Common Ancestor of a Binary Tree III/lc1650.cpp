// 2022 5.26 12：16
// 2022 5.26 12:43 - (Sloved, but review the 236's code!)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* findOrigin(Node* p) {
        Node* cur = p;
        while(cur->parent != nullptr) cur = cur->parent;
        return cur;
    }
    Node* find(Node* root, Node* p, Node* q) {
        if(root == nullptr) return root;
        if(root == p || root == q) return root;
        Node* left = find(root->left, p, q);
        Node* right = find(root->right, p, q);
        if(left != nullptr && right != nullptr) return root;
        return left != nullptr ? left : right;
    }
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node* root = findOrigin(p);
        return find(root, p, q);
    }
};