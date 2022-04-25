class Solution {
public:
    stack<char> pareSt;
    bool isValid(string s) {
        for (int i = 0; i < s.length(); i++) {
            switch (s[i]) {
            case '(':
                pareSt.push('(');
                break;
            case '[':
                pareSt.push('[');
                break;
            case '{':
                pareSt.push('{');
                break;
            case ')':
                if (pareSt.empty() || pareSt.top() != '(') return false;
                pareSt.pop();
                break;
            case ']':
                if (pareSt.empty() || pareSt.top() != '[') return false;
                pareSt.pop();
                break;
            case '}':
                if (pareSt.empty() || pareSt.top() != '{') return false;
                pareSt.pop();
                break;
            }
        }
        if (pareSt.empty()) return true;
        else return false;
    }
};