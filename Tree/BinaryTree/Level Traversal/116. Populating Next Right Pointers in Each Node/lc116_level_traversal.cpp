// 2022 5.10 22:03
// 2022 5.10 22:11
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
    Node* connect(Node* root) {
        if(root == nullptr) return nullptr;
        queue<Node*> que;
        que.push(root);
        Node* cur = nullptr;
        while(!que.empty()) {
            int size = que.size();
            for(int i = 0; i < size - 1; i++) {
                cur = que.front(); que.pop();
                if(cur->left != nullptr) que.push(cur->left);
                if(cur->right != nullptr) que.push(cur->right);
                cur->next = que.front();
            }
            cur = que.front();
            cur->next = nullptr;
            if(cur->left != nullptr) que.push(cur->left);
            if(cur->right != nullptr) que.push(cur->right);            
            que.pop();
        }
        return root;
    }
};