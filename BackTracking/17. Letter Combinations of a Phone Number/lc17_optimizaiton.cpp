class Solution {
public:
    const string lettermap[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    vector<string> result;
    string path;
    void backtracking(int startIndex, string& digits) {
        if (path.size() == digits.length()) {
            result.push_back(path);
            return;
        }
        int num = digits[startIndex] - '0'; // https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
        string s = lettermap[num];
        for (int i = 0; i < s.size(); i++) {
            path.push_back(s[i]);
            backtracking(startIndex + 1, digits);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.length() > 0)  backtracking(0, digits);
        return result;
    }
};