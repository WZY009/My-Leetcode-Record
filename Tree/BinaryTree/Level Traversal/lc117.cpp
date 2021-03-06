/*
// Definition for a Node.
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
        queue<Node*> que;
        if (root != nullptr) que.push(root);
        while (!que.empty()) {
            Node* curNode = nullptr;
            int size = que.size();
            for (int i = 0; i < size - 1; i++) {
                curNode = que.front();
                que.pop();
                curNode->next = que.front();
                if (curNode->left != nullptr) que.push(curNode->left);
                if (curNode->right != nullptr) que.push(curNode->right);
            }
            curNode = que.front();
            que.pop();
            curNode->next = nullptr;
            if (curNode->left != nullptr) que.push(curNode->left);
            if (curNode->right != nullptr) que.push(curNode->right);
        }
        return root;
    }
};