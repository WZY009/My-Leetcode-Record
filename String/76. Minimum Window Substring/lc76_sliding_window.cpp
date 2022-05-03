// 2022 5.3 19:06
// 2022 5.3 19:22
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<int, int> window, target;
        for(auto c : t) target[c]++; // create target map
        int left = 0; int right = 0;
        int valid = 0; // pay attention! the valid refers to the eligible clusters of same char, instead of single char!
        int start = 0; int len = INT_MAX;
        while(right <= s.size()) {
            char temp1 = s[right];
            right++;
            if(target.find(temp1) != target.end()) { // if the element is found in the target string
                window[temp1]++;
                if(window[temp1] == target[temp1]) valid++;
            }
            while(valid == target.size()) { 
                if(right - left < len) { // check whether we should update the minimum length
                    start = left;
                    len = right - left;
                }
                char temp2 = s[left];
                left++;
                if(target.find(temp2) != target.end()) { // if the element is found in the target string
                    if(window[temp2] == target[temp2]) valid--; // pay attention to the order!
                    window[temp2]--;
                }
            }
        }
        return (len == INT_MAX)? "" : s.substr(start, len);
    }
};