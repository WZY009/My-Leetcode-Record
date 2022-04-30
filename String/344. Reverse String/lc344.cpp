// 2022 4.30 17:02
// 2022 4.30 17:02 - 无脑直接过
class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i = 0, j = s.size() - 1; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }
};