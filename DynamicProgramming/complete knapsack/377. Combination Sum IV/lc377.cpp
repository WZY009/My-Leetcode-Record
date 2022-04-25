class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp (target + 1, 0);
        dp[0] = 1;
        for(int i = 0; i <= target; i++) {
            // we should traverse the weight first so as to get Permutation
            for(int j = 0; j < nums.size(); j++) {
                if(i >= nums[j] && dp[i] < INT_MAX - dp[i - nums[j]])
                    // dp[i] + dp[i - nums[j]] might be larger than int scale
                    dp[i] += dp[i - nums[j]];
            }
        }
        return dp[target];
    }
};