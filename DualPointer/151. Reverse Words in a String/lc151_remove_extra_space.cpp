class Solution {
    // about string::size and string::length //https://stackoverflow.com/questions/905479/stdstring-length-and-size-member-functions
public:
    void reverse(string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }
    void removeSpace(string& s) {
        int slow = 0;
        int fast = 0;
        //remove the beginning space
        while (s.length() > 0 && fast < s.length() && s[fast] == ' ') fast++;
        // remove the redundant space between two words
        for (; fast < s.length(); fast++) {
            if (fast - 1 > 0 && s[fast - 1] == s[fast] && s[fast] == ' ')
                continue;
            else
                s[slow++] = s[fast];
        }
        // remove the end space
        if (slow - 1 > 0 && s[slow - 1] == ' ')// the last one is space
            s.resize(slow - 1);
        else
            s.resize(slow);//the last one is character
    }
    string reverseWords(string s) {
        removeSpace(s);
        reverse(s, 0, s.length() - 1);
        int start = 0;
        int end = 0;
        bool isEntry = false;
        for (int i = 0; i < s.length(); i++) {
            if ((!isEntry) || (s[i] != ' ' && s[i - 1] == ' ')) {//find the start of the word
                start = i;
                isEntry = true;
            }
            if (isEntry && s[i] == ' ' && s[i - 1] != ' ') { // find the end of the word
                end = i - 1;
                isEntry = false;
                reverse(s, start, end);
            }
            if (isEntry && i == s.length() - 1) {// arriving the end
                end = i;
                reverse(s, start, end);
            }
        }
        return s;
    }
};