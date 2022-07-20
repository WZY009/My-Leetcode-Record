// 2022 5.10 22:03
// 2022 5.10 22:11
// 2022 5.10 22:32 - viewing the answer
/*
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void traversal(Node* node1, Node* node2) {
        if(node1 == nullptr || node2 == nullptr) return;
        
        traversal(node1->left, node1->right);        
        
        traversal(node1->right, node2->left);
        
        traversal(node2->left, node2->right);
        // This operation can show in anywhere!
        node1->next = node2;

    }
    Node* connect(Node* root) {
        if(root == nullptr) return nullptr;
        traversal(root->left, root->right);
        return root;
    }
};