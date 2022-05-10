// 2022 5.10 16:15 ~ 16:20(no any good ideas)
// 2022 5.10 19:10 ~ 19:24 (one review about isInStack's data structure)
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int count[26] = {0};
        for(char c : s) count[c - 'a']++;
        bool isInStack[26] = {false};
        stack<char> st;
        string res;
        for(char cur : s) {
            // count means when you focus on s[i], whether the same character exist after this position.
            count[cur - 'a']--;
            if(isInStack[cur - 'a']) continue;
            while(!st.empty() && st.top() > cur) {
                // If the same character doesn't exist after this position, don't get rid of it although it's lexicographical is bigger than the current character.
                if(count[st.top() - 'a'] == 0) break;
                // If we have same char after this position, you can pop it out caz its big lexicographical order. Remember to set isInStack again!
                isInStack[st.top() - 'a'] = false;
                st.pop();     
            }
            st.push(cur);
            isInStack[cur - 'a'] = true;
        }    
        while(!st.empty()) {
            res.push_back(st.top()); 
            st.pop();
        } 
        reverse(res.begin(), res.end());
        return res;
    }
};