// in this case, you don't need to initalize dp.
// when the nums[0] == 0, dp[1][0] == 2, caz the first zero can be positive or negative. 
// Although the 1-D is easier to code, but you still have to understand each detail of it.
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int i : nums) sum += i;
        if(sum < abs(target) || (target + sum) % 2 == 1) return 0;
        int bagSize  = (target + sum) / 2;
        vector<int> dp (bagSize + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = bagSize; j >= nums[i]; j--)
                dp[j] += dp[j - nums[i]];
        }
        return dp[bagSize];
    }
};