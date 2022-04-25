class Solution {
public:
    vector<string> result;

    bool isValid(const string& s, int start, int end) { // both side are closed 
        if (start > end)
            return false;
        if (s[start] == '0' && start != end)
            return false;
        int num = 0;
        for (int i = start; i <= end; i++) {// why you choose use a loop to calculate the number instead of atoi()? --because atoi() is not capable to check if the character is valid!
            if (s[i] > '9' || s[i] < '0') return false;
            num = num * 10 + (int)(s[i] - '0');
            if (num > 255) return false;
        }
        return true;
    }

    void backtracking(string& s, int startIndex, int pointNum) {
        if (pointNum == 3) {
            if (isValid(s, startIndex, s.size() - 1))
                result.push_back(s);
            return;
        }
        for (int i = startIndex; i < s.size(); i++) {
            if (isValid(s, startIndex, i)) {
                s.insert(s.begin() + i + 1, '.');
                pointNum++;
                backtracking(s, i + 2, pointNum);
                pointNum--;
                s.erase(s.begin() + i + 1);

            }
            else break;
        }
    }

    vector<string> restoreIpAddresses(string s) {
        if (s.size() <= 12) backtracking(s, 0, 0);
        return result;
    }
};