// complete knapsack
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        // pay attention! classical knapsack problem can reverse the item loop and weight loop.
        // but In this case, you can't do that. Because the outer loop is items loop, which can 
        // prevent repeatition.
        // you should know that it is combination, instead of Permutation.
        for(int i = 0; i < coins.size(); i++) {
            for(int j = coins[i]; j <= amount; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};