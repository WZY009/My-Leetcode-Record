class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int len = nums.size();
        int result = 1;
        vector<int> dp(len, 1);
        for(int i = 0; i < len - 1; i++) {
            if(nums[i + 1] > nums[i]) dp[i + 1] = dp[i] + 1;
            result = max(result, dp[i + 1]);
        }
        return result;
    }
};