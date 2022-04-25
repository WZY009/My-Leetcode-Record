class Solution {
    // the difference between 454 and 18 is whether the duplicate should be dropped
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4) return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size() - 2; j++) {
                // if(nums[j] == nums[j - 1]) continue; deleting the dulicates should not just like this, there are two version acceptable. I made this version, but I think the code by Carl is better!
                // if(j > i + 1 && nums[j] == nums[j - 1]) // this can also be a way to remove duplicate
                int left = j + 1;
                int right = nums.size() - 1;
                while (right > left) {
                    if (nums[i] + nums[j] < target - (nums[left] + nums[right])) left++;
                    else if (nums[i] + nums[j] > target - (nums[left] + nums[right])) right--;
                    else {
                        result.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        while (right > left && nums[left] == nums[left + 1]) left++;
                        while (right > left && nums[right] == nums[right - 1]) right--;
                        right--;
                        left++;
                    }
                }
                while (j < nums.size() - 2 && nums[j] == nums[j + 1]) {
                    j++;
                }
            }
        }
        return result;
    }
};

