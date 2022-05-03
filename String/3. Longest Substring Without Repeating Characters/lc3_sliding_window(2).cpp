// 2022 5.3 20:27
// edition 1  2022 5.3 21:08
// edition 2  2022 5.3 21：31 看了答案，思路一致，但就是没想到用window[c] > 1作为条件
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        unordered_map<int, int> window;
        int left = 0;
        int right = 0;
        int maxLen = 1;
        while(right < s.size()) {
            char c = s[right];
            right++;
            window[c]++;
            while(window[c] > 1) {
                char d = s[left];
                left++;
                window[d]--;
            }
            maxLen = maxLen > right - left ? maxLen : right - left;
        }
        return maxLen;
    }
};