// this problem is the transformation of 0/1 knapsack problem but in this problem the num[i] serves as weight[i] and value[i]
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int size = nums.size();
        int sum = 0;
        for (int i = 0; i < size; i++) 
            sum += nums[i];        
        if (sum % 2 == 1) return false; // if sum is odd number. You can not reach to it's half no matter what you select!
        vector<vector<int>> dp (size, vector<int>(sum / 2 + 1, 0));
        for (int j = nums[0]; j <= sum / 2; j++) {
            dp[0][j] = nums[0];
        }
        for (int i = 1; i < size; i++) {
            for (int j = 0; j <= sum / 2; j++) {
                if (j < nums[i]) dp[i][j] = dp[i - 1][j]; // when the calpacity of the bag is smaller than this item, skip this item!
                else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]); 
                if(dp[i][j] == sum / 2) return true;
            } 
        }
        return false;
    }
};