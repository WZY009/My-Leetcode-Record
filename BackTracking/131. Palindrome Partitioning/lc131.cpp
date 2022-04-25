class Solution {
public:
    vector<vector<string>> result;
    vector<string> path;
    
    bool isPartition(const string& s, int start, int end) {
        for(int i = start, j = end; i < j; i++, j--) {
            if(s[i] != s[j]) return false;
        }
        return true;
    }
    
    void backtracking(const string& s, int startIndex) {
        if(startIndex >= s.size()) {
            result.push_back(path);
            return;
        }
        for(int i = startIndex; i < s.size(); i++) {
            if(isPartition(s, startIndex, i)) {
                string str = s.substr(startIndex, i - startIndex + 1);
                path.push_back(str);
            }
            else continue;
            backtracking(s, i + 1);
            path.pop_back();
        }
    }
    
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return result;
    }
};