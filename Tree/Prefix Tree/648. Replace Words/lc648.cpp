// 2022 6.29 8:44 ~ 9：13 (Viewing the answer!)
class Trie{
private:
    vector<Trie*> children;
    bool isEnd;
public:
    Trie() : children(26), isEnd(false) {}
    
    void insert(const string& s) {
        Trie* node = this;
        for(char ch : s) {
            ch -= 'a';
            if(!node->children[ch])  nod648. Replace Wordse->children[ch] = new Trie();
            node = node->children[ch];
        }
        node->isEnd = true;
    }
    
    string searchPrefix(string s) {
        string ans;
        Trie* node = this;
        for(char ch : s) {            
            if(node->children[ch - 'a']){
                ans += ch;
                node = node->children[ch - 'a'];
            } else break;
            if(node->isEnd) return ans;
        }
        return node->isEnd ? ans : "";
    }
    
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        stringstream ss; // a new API to handle the split of a string
        ss << sentence;
        string str;
        string ans;
        Trie* root = new Trie();
        for(string& s : dictionary) root->insert(s);
        while(ss >> str) {
            string temp = root->searchPrefix(str);
            if(temp.size()) ans += temp;
            else ans += str;
            ans += ' ';
        }
        return ans.substr(0, ans.size() - 1); // the last one will be the space!
    }
};