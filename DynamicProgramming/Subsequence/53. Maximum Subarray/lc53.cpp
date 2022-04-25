class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> dp(nums.size()); // dp[i] means the maximum sum of subsequence with the end of i
        dp[0] = nums[0];
        int result = dp[0];// pay attention! you can't initialize the result as INT_MIN because [-1, -2] will be wrong!
        for(int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            result = max(result, dp[i]);
        }
        return result;
    }
};