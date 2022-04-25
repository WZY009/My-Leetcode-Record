class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i * i <= n; i++) { // traverse items
            for(int j = 1; j <= n; j++) { // traverse volume
                if(j - i * i >= 0)
                    dp[j] = min(dp[j], dp[j - i * i] + 1);
            }
        }
        return dp[n];
    }
};