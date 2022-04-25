// this problem is the transformation of 0/1 knapsack problem but in this problem the num[i] serves as weight[i] and value[i]
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int size = nums.size();
        int sum = 0;
        for (int i = 0, j = size - 1; i <= j; i++, j--) 
            if (i == j) sum += nums[i];
            else sum += nums[i] + nums[j];        
        if (sum % 2 == 1) return false; // if sum is odd number. You can not reach to it's half no matter what you select!        
        sum /= 2;        
        vector<int> dp (sum + 1, 0);
        for (int j = nums[0]; j <= sum; j++) 
            dp[j] = nums[0];
        
        // although you use one-dimensional DP array, you should still have the awareness of two-dimension DP array
        for (int i = 1; i < size; i++) {
            for(int j = sum; j >= nums[i]; j--) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]); 
                if(dp[j] == sum) return true;                
            }
        }
        return false;
    }
};