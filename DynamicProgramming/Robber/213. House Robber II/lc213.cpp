class Solution {
public:
    int robber (vector<int>& nums, int start, int end) {
        if(end == start) return nums[start]; // this row is to prevent array with length 2
        vector<int> dp(nums.size());
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);
        for(int i = start + 2; i <= end; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[end];
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int result1 = robber(nums, 1, nums.size() - 1);
        int result2 = robber(nums, 0, nums.size() - 2);        
        return max(result1, result2);
    }
};