class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        deque<pair<TreeNode*, long long>> que; // we store a pair, so we don't need to worry about integer overflow!
        que.emplace_back(root,0);
        int res = 1;
        while(!que.empty()){
            int sz = que.size();
            long long Min = que.front().second;
            long long Max = que.back().second;
            // get the leftmost node and rightmost node
            int width = Max - Min + 1;
            cout << Max << ' ' << Min << endl;
            cout << width << endl;
            // if(width <= 0) width += INT_MAX; // If Max < Min, it means Max operates remainder one more time!
            long long offset = que.front().second;
            res = max(res, width);
            for(int i = 0; i < sz; i++){
                auto node = que.front().first;
                // long long index = que.front().second % INT_MAX;
                long long index = que.front().second;
                que.pop_front();
                if(node->left) que.emplace_back(node->left, index * 2- offset * 2); // You have to use long long and minus offset to prevent integer overflow!
                if(node->right) que.emplace_back(node->right, index * 2 + 1 - offset * 2);
            } 
        }
        return res;
    }
};
