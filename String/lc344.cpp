class Solution {
public:
    void reverseString(vector<char>& s) {
        // clown is me! I mistake the i and j!
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }
};