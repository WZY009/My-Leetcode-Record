class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if(len == 0) return 0;
        vector<vector<int>> dp(len, vector<int>(2 * k + 1));
        dp[0][0] = 0;
        for(int i = 1; i < 2 * k + 1; i += 2) {
            dp[0][i] = -prices[0];
            dp[0][i + 1] = 0;
        }
        for(int i = 1; i < len; i++) {
            dp[i][0] = dp[i - 1][0];
            for(int j = 1; j < 2 * k + 1; j += 2) {
                dp[i][j] = max(dp[i - 1][j], -prices[i] + dp[i - 1][j - 1]);
                dp[i][j + 1] = max(dp[i - 1][j + 1], prices[i] + dp[i - 1][j]);
            }
        }
        return dp[len - 1][2 * k];
    }
};