class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int MinLength = INT32_MAX;//set the MinLength to the maximum value
        int sum = 0;
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (sum >= target) {
                MinLength = (i - j + 1) < MinLength ? (i - j + 1) : MinLength;
                sum -= nums[j];
                j++;
            }
        }
        return MinLength == INT32_MAX ? 0 : MinLength;
    }
};