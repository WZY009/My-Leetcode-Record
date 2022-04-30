// 2022 4.30 17:00

class Solution {
public:
    string palindrome(string& s, int left, int right) { // crucial! it's spreading from middle to two sides
        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }
    string longestPalindrome(string s) {
        string result;
        for(int i = 0; i < s.size(); i++) {
            string s1 = palindrome(s, i, i);
            string s2 = palindrome(s, i, i + 1);
            result = result.size() > s1.size() ? result : s1;
            result = result.size() > s2.size() ? result : s2;
        }
        return result;
    }
};