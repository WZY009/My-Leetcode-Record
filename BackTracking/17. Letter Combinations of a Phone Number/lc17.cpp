class Solution {
public:
    vector<string> result;
    string path;

    string convert(int num) { // it may slow down because it will recall the creation of function and using unnecessary for-loop
        string s;
        if (num >= 2 && num <= 6) {
            int ascii = 91 + 3 * num;
            for (int i = 0; i < 3; i++) {
                s = s + (char)ascii;
                ascii++;
            }
            return s;
        }
        else {
            switch (num) {
            case 7:
                return "pqrs";
            case 8:
                return "tuv";
            case 9:
                return "wxyz";
            }
            return s;
        }
    }
    void backtracking(int startIndex, string& digits) {
        if (path.size() == digits.length()) {
            result.push_back(path);
            return;
        }
        int num = digits[startIndex] - '0'; // https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
        string s = convert(num);
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