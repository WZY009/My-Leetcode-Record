// 2022 5.3 20:27
// edition 1  2022 5.3 21:08

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        unordered_map<int, int> window;
        int maxLen = 1;
        for(int i = 0; i < s.size() - 1; i++) {
            window[s[i]]++;
            int index = i + 1;
            while(index < s.size()) {
                char c = s[index];
                if(window[c] != 0) {
                    maxLen = maxLen > (index - i) ? maxLen : (index - i);
                    for(int j = index - 1; j > i; j--) {
                        window[s[j]]--;
                    }
                    break;
                }
                window[c]++;
                index++;
            }
            maxLen = maxLen > (index - i) ? maxLen : (index - i);
            window[s[i]]--;
        }
        return maxLen;
    }
};