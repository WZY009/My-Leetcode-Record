// 2022 6.29 16:00 ~ 16；27
struct TrieNode{
    int value;
    vector<TrieNode*> children;
    TrieNode() : value(0), children(26) {}
};

class MapSum {
private:
    TrieNode* root;
    
    int dfs(TrieNode* root) {
        if(!root) return 0;
        int res = root->value;
        for(int i = 0; i < 26; i++) {
            res += dfs(root->children[i]);
        }
        return res;
    }
public:
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        TrieNode* node = root;
        for(char ch : key) {
            ch -= 'a';
            if(!node->children[ch]) node->children[ch] = new TrieNode();
            node = node->children[ch];
        }
        node->value = val;
    }
    
    int sum(string prefix) {
        TrieNode* node = root;
        for(char ch : prefix) {
            ch -= 'a';
            if(!node->children[ch]) return 0;
            node = node->children[ch];
        }
        // At this time, the node points to the last char of the prefix. We should traverse all the non-empty nodes under this node.
        return dfs(node);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */