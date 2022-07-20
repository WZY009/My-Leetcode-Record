class Trie {
private:
    bool isEnd;
    vector<Trie*> children;
    
    Trie* searchPrefix(const string& s) {
        Trie* node = this;
        for(char ch : s) {
            ch -= 'a';
            if(node->children[ch] == nullptr) {
                return nullptr;
            }
            node = node->children[ch];
        }
        return node;
    }
public:
    Trie() : children(26), isEnd(false)  {}
    
    void insert(string word) {
        Trie* node = this;
        for(char ch : word) {
            ch -= 'a';
            if(node->children[ch] == nullptr) node->children[ch] = new Trie();
            node = node->children[ch];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie* result = this->searchPrefix(word);
        return result != nullptr && result->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* result = this->searchPrefix(prefix);
        return result != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */