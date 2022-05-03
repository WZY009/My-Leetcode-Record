// 2022 5.3 19:40
//
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        unordered_map<int, int> window, need;
        for(auto c : s1) need[c]++;
        int left = 0; 
        int right = s1.size() - 1;
        int valid = 0;
        for(int i = left; i <= right; i++) {
            char c = s2[i];
            if(need.find(c) != need.end()) { // if the char shows in the s1 
                window[c]++;
                if(window[c] == need[c]) valid++;
            }
        }
        while(right < s2.size()) {
            //check whether the window is eligible or not
            //if yes, return ture
            //if no, go ahead
            if(valid == need.size()) return true;
            char c1 = s2[left];
            left++;
            right++;
            char c2 = s2[right];
            if(need.find(c1) != need.end()) {
                if(window[c1] == need[c1]) valid--;
                window[c1]--;
            }
            if(need.find(c2) != need.end()) { // if the char shows in the s1 
                window[c2]++;
                if(window[c2] == need[c2]) valid++;
            }            
        }
        return false;
    }
};