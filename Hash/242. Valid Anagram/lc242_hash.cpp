class Solution {
public:
    bool isAnagram(string s, string t) {
        int hash[26] = { 0 };
        int size = s.length();
        if (t.length() != size) return false;
        for (int i = 0; i < size; i++)
            hash[s[i] - 'a']++;
        for (int j = 0; j < size; j++)
            hash[t[j] - 'a']--; // I don't know why I made a mistake here
        for (int k = 0; k < 26; k++) {//remember to go through the array
            if (hash[k] != 0) return false;
        }
        return true;
    }
};
