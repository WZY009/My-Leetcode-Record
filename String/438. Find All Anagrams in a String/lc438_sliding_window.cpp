// 2022 5.3 20:11
// 2022 5.3 20:24
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size()) return {};
        unordered_map<int, int> window, need;
        for(char c : p) need[c]++;
        int left = 0;
        int right = p.size() - 1;
        int valid = 0;
        vector<int> vec;
        for(int i = left; i <= right; i++) {
            char c = s[i];
            if(need.find(c) != need.end()) {
                window[c]++;
                if(window[c] == need[c]) valid++;
            }
        }
        while(right < s.size()) {
            if(valid == need.size()) vec.push_back(right - p.size() + 1);
            char c1 = s[left];
            left++;
            if(need.find(c1) != need.end()) {
                if(window[c1] == need[c1]) valid--;
                window[c1]--;
            }
            right++;
            char c2 = s[right];
            if(need.find(c2) != need.end()) {
                window[c2]++;
                if(window[c2] == need[c2]) valid++;
            }            
        }
        return vec;
    }
};