class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        bool dp[301] = {false};
        // dp[i] means the substring of s from s[0] to s[i] forms a word break unit
        int length = s.size();
        dp[0] = true;
        for(int i = 1; i <= length; i++) { // traverse bag
            for(int j = 0; j < i; j++) {
                string str = s.substr(j, i - j); // pay attention! you don't need the s[i]!
                if(wordSet.find(str) != wordSet.end() && dp[j]) { // if the str can be found in the dict and the dp[j] conforms the word break request.
                    dp[i] = true;
                    break;
                }                
            }
        }
        return dp[length];
    }
};