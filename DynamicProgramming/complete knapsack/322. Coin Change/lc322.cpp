class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp (amount + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i < coins.size(); i++) {
            for(int j = coins[i]; j <= amount; j++) {
                if(dp[j - coins[i]] != INT_MAX){ 
                    // if you don't have this condition, INT_MAX + 1 will overflow.
                    dp[j] = min(dp[j - coins[i]] + 1, dp[j]);                   
                }               
            }
        }
        if(dp[amount] == INT_MAX) return -1;
        else return dp[amount];
    }
};