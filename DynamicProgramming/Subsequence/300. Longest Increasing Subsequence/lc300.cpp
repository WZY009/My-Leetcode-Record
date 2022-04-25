class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if(len == 1) return 1;
        int result = 0;
        vector<int> dp(len, 1);
        for(int i = 1; i < len; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
            }
            result = max(dp[i], result);
        }
        return result;
    }
};