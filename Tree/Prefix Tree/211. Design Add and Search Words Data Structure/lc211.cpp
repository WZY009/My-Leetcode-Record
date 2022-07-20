

struct TrieNode{
    vector<TrieNode*> children;
    bool isEnd;
    TrieNode() : children(26, nullptr), isEnd(false) {}
};

class WordDictionary {
private:
    TrieNode* root;
    
public:
    WordDictionary() {
        root = new TrieNode(); 
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for(char ch : word) {
            ch -= 'a';
            if(!node->children[ch]) node->children[ch] = new TrieNode();
            node = node->children[ch];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        return dfs(root, 0, word);
    }
    
    bool dfs(TrieNode* node, int index, const string& s) {
        if(index == s.size()) return node->isEnd;
        char ch = s[index];
        if(ch >= 'a' && ch <= 'z') {
            ch -= 'a';
            TrieNode* child = node->children[ch];
            if(!child) return false;
            else return dfs(child, index + 1, s);
        } else if(ch == '.') {
            for(int i = 0; i < 26; i++) {
                if(node->children[i] && dfs(node->children[i], index + 1, s)) return true;
            }
        }
        return false;
    }
    
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */