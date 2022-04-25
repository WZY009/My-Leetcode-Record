/*
this problem is not very easy especially when you do it first time.
The first thing is to divide the array into two parts, the first part is postitive while another one is minus.
As you know, the target = positive part + (sum - postive part)(negative part)
Thus, positive part must equal to (target + sum) / 2 of course if target + sum is an odd number, the result is 0.
now, the problem becomes a 0/1 package problem. the question is: how can you choose the combination of positive number (the negative one confirms after you select positive one) so as to their sum reaches to 
(target + sum) / 2 ?
let's define a DP array. dp[i] means from nums[0] to nums[i], how many conmbination you can select and then add them together so as to equal to (target + sum) / 2.
dp[j] = dp[j] + dp[j - nums[i]];
that means if a bag volume is j, the dp[j] is made up of previous dp[j](i - 1) and dp[j - nums[i]]
the explanation can go to https://github.com/youngyangyang04/leetcodemaster/blob/master/problems/0494.%E7%9B%AE%E6%A0%87%E5%92%8C.md
*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        if(nums.size() == 1) {
            if(abs(target) == nums[0]) return 1;
            else return 0;
        }
        for(int i : nums) sum += i;
        if(sum < abs(target) || (target + sum) % 2 == 1) return 0;
        int bagSize = (target + sum) / 2;
        vector<vector<int>> dp (nums.size(), vector<int> (bagSize + 1, 0));
        dp[0][0] = 1;
        dp[0][nums[0]] += 1; // to prevent the first one as 0 because 0 have two conditions
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j <= bagSize; j++) {
                if (j < nums[i]) dp[i][j] = dp[i - 1][j];
                else 
                    dp[i][j] += dp[i - 1][j - nums[i]] + dp[i - 1][j]; // remember to add the upper row's data!
            }
        }
        return dp[nums.size() - 1][bagSize];
    }
};